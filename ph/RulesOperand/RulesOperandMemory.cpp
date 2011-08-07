
#include "../DataTypes.h"
#include "../GlobalVariables.h"

#include "../stdafx.h"
//#include "stdafx.h" //SMark

#include "../RulesOperand.h"
#include "RulesOperandMemory.h"

//Global Memory Operand
struct OperandRuleGlobalMemoryWithImmediate32: OperandRule
{
	OperandRuleGlobalMemoryWithImmediate32(): OperandRule(GlobalMemoryWithImmediate32){}
	virtual void Process(SubString &component)
	{
		unsigned int memory; int register1;
		component.ToGlobalMemory(register1, memory);
		//Check max reg when register is not RZ(63)
		if(register1!=63)
			csMaxReg = (register1 > csMaxReg)? register1: csMaxReg;

		csCurrentInstruction.OpcodeWord0 |= register1<<20; //RE1
		WriteToImmediate32(memory);
	}
}OPRGlobalMemoryWithImmediate32;

//SharedMemory operand
struct OperandRuleSharedMemoryWithImmediate20: OperandRule
{
	OperandRuleSharedMemoryWithImmediate20(): OperandRule(SharedMemoryWithImmediate20){}
	virtual void Process(SubString &component)
	{
		unsigned int memory; int register1;
		component.ToGlobalMemory(register1, memory);

		if(memory>=1<<20) //issue: not sure if negative hex is gonna work
			throw 130; //cannot be longer than 20 bits
		//Check max reg when register is not RZ(63)
		if(register1!=63)
			csMaxReg = (register1 > csMaxReg)? register1: csMaxReg;

		csCurrentInstruction.OpcodeWord0 |= register1<<20; //RE1
		WriteToImmediate32(memory);
	}
}OPRSharedMemoryWithImmediate20;



//Constant Memory Operand
struct OperandRuleConstantMemory: OperandRule
{
	OperandRuleConstantMemory() : OperandRule(ConstantMemory){}
	virtual void Process(SubString &component)
	{		
		unsigned int bank, memory;
		int register1;
		component.ToConstantMemory(bank, register1, memory);
		if(register1!=63)
			csMaxReg = (register1 > csMaxReg)? register1: csMaxReg;

		csCurrentInstruction.OpcodeWord0 |= register1<<20; //RE1
		csCurrentInstruction.OpcodeWord1 |= bank<<10;
		WriteToImmediate32(memory);
		//no need to do the marking for constant memory
	}
}OPRConstantMemory;


struct OperandRuleGlobalMemoryWithLastWithoutLast2Bits: OperandRule
{
	OperandRuleGlobalMemoryWithLastWithoutLast2Bits(): OperandRule(GlobalMemoryWithImmediate32)
	{
	}
	virtual void Process(SubString &component)
	{
		unsigned int memory;
		int reg1;
		component.ToGlobalMemory(reg1, memory);
		if(memory%4!=0)
			throw 138;//address must be multiple of 4

		if(reg1!=63)
			csMaxReg = (reg1 > csMaxReg)? reg1: csMaxReg;
		csCurrentInstruction.OpcodeWord0 |= reg1<<20; //RE1
		WriteToImmediate32(memory);

	}
}OPRGlobalMemoryWithLastWithoutLast2Bits;

struct OperandRuleMemoryForATOM: OperandRule
{
	OperandRuleMemoryForATOM(): OperandRule(Custom){}
	virtual void Process(SubString &component)
	{
		unsigned int memory;
		int reg1;
		bool negative = false;
		component.ToGlobalMemory(reg1, memory);
		if(memory&0x80000000)
		{
			memory--;
			memory ^= 0xFFFFFFFF;
		}
		if(memory>0x7ffff)
			throw 141; //20-bit signed integer
		if(negative)
		{
			memory ^= 0xFFFFFFFF;
			memory++;
			memory &= 0x000fffff;
		}
		csCurrentInstruction.OpcodeWord0 |= memory << 26;
		csCurrentInstruction.OpcodeWord1 |= (memory&0x0001ffff)>>6;
		csCurrentInstruction.OpcodeWord1 |= (memory&0x000e0000)<<6;
		csCurrentInstruction.OpcodeWord0 |= reg1<<20;
	}
}OPRMemoryForATOM;