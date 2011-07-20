#ifndef RulesInstructionDataMovementDefined

struct INstructionRuleMOV: InstructionRule
{
	INstructionRuleMOV(): InstructionRule("MOV", 0, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("0010011110111000000000000000000000000000000000000000000000010100", OpcodeWord0, OpcodeWord1);
		SetOperands(2, 
					&OPRRegister0,
					&OPRMOVStyle);
	}
}IRMOV;

struct INstructionRuleMOV32I: InstructionRule
{
	INstructionRuleMOV32I(): InstructionRule("MOV32I", 0, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("0100011110111000000000000000000000000000000000000000000000011000", OpcodeWord0, OpcodeWord1);
		SetOperands(2, 
					&OPRRegister0,
					&OPR32I);
	}
}IRMOV32I;




struct InstructionRuleLD: InstructionRule
{
	InstructionRuleLD() : InstructionRule("LD", 2, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("1010000100111000000000000000000000000000000000000000000000000001", OpcodeWord0, OpcodeWord1);
		SetOperands(2, 
					&OPRRegister0,					
					&OPRGlobalMemoryWithImmediate32);
		ModifierGroups[0].Initialize(true, 3,
					&MRLDCopCG,
					&MRLDCopCS,
					&MRLDCopCV);
		ModifierGroups[1].Initialize(true, 6,
					&MRLDU8,
					&MRLDS8,
					&MRLDU16,
					&MRLDS16,
					&MRLD64,
					&MRLD128);
	}
}IRLD;


struct InstructionRuleLDU: InstructionRule
{
	InstructionRuleLDU() : InstructionRule("LDU", 1, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("1010000100111000000000000000000000000000000000000000000000010001", OpcodeWord0, OpcodeWord1);
		SetOperands(2, 
					&OPRRegister0,					
					&OPRGlobalMemoryWithImmediate32);
		ModifierGroups[0].Initialize(true, 6,
					&MRLDU8,
					&MRLDS8,
					&MRLDU16,
					&MRLDS16,
					&MRLD64,
					&MRLD128);
	}
}IRLDU;


struct InstructionRuleLDL: InstructionRule
{
	InstructionRuleLDL() : InstructionRule("LDL", 2, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("1010000100111000000000000000000000000000000000000000000000000011", OpcodeWord0, OpcodeWord1);
		SetOperands(2, 
					&OPRRegister0,					
					&OPRGlobalMemoryWithImmediate32);
		ModifierGroups[0].Initialize(true, 3,
					&MRLDCopCG,
					&MRLDCopLU,
					&MRLDCopCV);
		ModifierGroups[1].Initialize(true, 6,
					&MRLDU8,
					&MRLDS8,
					&MRLDU16,
					&MRLDS16,
					&MRLD64,
					&MRLD128);
	}
}IRLDL;

struct InstructionRuleLDS : InstructionRule
{
	InstructionRuleLDS(): InstructionRule("LDS", 1, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("1010000100111000000000000000000000000000000000000000000010000011", OpcodeWord0, OpcodeWord1);
		SetOperands(2,
					&OPRRegister0,
					&OPRSharedMemoryWithImmediate20);
		ModifierGroups[0].Initialize(true, 6,
					&MRLDU8, 
					&MRLDS8, 
					&MRLDU16, 
					&MRLDS16, 
					&MRLD64, 
					&MRLD128);
	}
}IRLDS;

struct InstructionRuleLDC : InstructionRule
{
	InstructionRuleLDC(): InstructionRule("LDC", 1, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("0110000100111000000000000000000000000000000000000000000000101000", OpcodeWord0, OpcodeWord1);
		SetOperands(2,
					&OPRRegister0,
					&OPRConstantMemory);
		ModifierGroups[0].Initialize(true, 6,
					&MRLDU8, 
					&MRLDS8, 
					&MRLDU16, 
					&MRLDS16, 
					&MRLD64, 
					&MRLD128);
	}
}IRLDC;

struct InstructionRuleST: InstructionRule
{
	InstructionRuleST() : InstructionRule("ST", 2, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("1010000100111000000000000000000000000000000000000000000000001001", OpcodeWord0, OpcodeWord1);
		SetOperands(2, 
					&OPRGlobalMemoryWithImmediate32,
					&OPRRegister0);
		ModifierGroups[0].Initialize(true, 3,
					&MRSTCopCG,
					&MRSTCopCS,
					&MRSTCopWT);
		ModifierGroups[1].Initialize(true, 6,
					&MRLDU8, 
					&MRLDS8, 
					&MRLDU16, 
					&MRLDS16, 
					&MRLD64, 
					&MRLD128);
	}
}IRST;


struct InstructionRuleSTL: InstructionRule
{
	InstructionRuleSTL() : InstructionRule("STL", 2, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("1010000100111000000000000000000000000000000000000000000000010011", OpcodeWord0, OpcodeWord1);
		SetOperands(2, 
					&OPRGlobalMemoryWithImmediate32,
					&OPRRegister0);
		ModifierGroups[0].Initialize(true, 3,
					&MRSTCopCG,
					&MRSTCopCS,
					&MRSTCopWT);
		ModifierGroups[1].Initialize(true, 6,
					&MRLDU8, 
					&MRLDS8, 
					&MRLDU16, 
					&MRLDS16, 
					&MRLD64, 
					&MRLD128);
	}
}IRSTL;

struct InstructionRuleSTS : InstructionRule
{
	InstructionRuleSTS(): InstructionRule("STS", 1, true, false)
	{
		InstructionRule::BinaryStringToOpcode8("1010000100111000000000000000000000000000000000000000000010010011", OpcodeWord0, OpcodeWord1);
		SetOperands(2,
					&OPRSharedMemoryWithImmediate20,
					&OPRRegister0);
		ModifierGroups[0].Initialize(true, 6,
					&MRLDU8, 
					&MRLDS8, 
					&MRLDU16, 
					&MRLDS16, 
					&MRLD64, 
					&MRLD128);
	}
}IRSTS;



#else
#define RulesInstructionDataMovementDefined
#endif