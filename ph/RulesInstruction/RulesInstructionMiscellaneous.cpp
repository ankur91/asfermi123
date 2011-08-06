
#include "../DataTypes.h"
#include "../helper/helperMixed.h"

#include "stdafx.h"

#include "RulesInstructionMiscellaneous.h"
#include "../RulesModifier.h"
#include "../RulesOperand.h"




struct InstructionRuleS2R: InstructionRule
{
	InstructionRuleS2R(): InstructionRule("S2R", 0, true, false)
	{
		hpBinaryStringToOpcode8("0010 000000 111000000000000000000000000000000000000000000000110100", OpcodeWord0, OpcodeWord1);
		SetOperands(2, &OPRRegister0, &OPRS2R);
	}
}IRS2R;

struct InstructionRuleLEPC: InstructionRule
{
	InstructionRuleLEPC(): InstructionRule("LEPC",0, true, false)
	{
		hpBinaryStringToOpcode8("0010 000000 111000000000000000000000000000000000000000000000 100010", OpcodeWord0, OpcodeWord1);
		SetOperands(1, &OPRRegister0);
	}

}IRLEPC;

struct InstructionRuleCCTL: InstructionRule
{
	InstructionRuleCCTL(): InstructionRule("CCTL", 3, true, false)
	{
		hpBinaryStringToOpcode8("1010 000000 1110 000000 000000 00 000000000000000000000000000000 0 11001", OpcodeWord0, OpcodeWord1);
		SetOperands(2,
					&OPRRegister0,
					&OPRGlobalMemoryWithLastWithoutLast2Bits);
		ModifierGroups[0].Initialize(true, 1, &MRE);
		ModifierGroups[1].Initialize(true, 3,
									&MRCCTLOp1U,
									&MRCCTLOp1C,
									&MRCCTLOp1I);
		ModifierGroups[2].Initialize(false, 8,
									&MRCCTLOp2QRY1,
									&MRCCTLOp2PF1,
									&MRCCTLOp2PF1_5,
									&MRCCTLOp2PR2,
									&MRCCTLOp2WB,
									&MRCCTLOp2IV,
									&MRCCTLOp2IVALL,
									&MRCCTLOp2RS);
	}
}IRCCTL;


struct InstructionRuleCCTLL: InstructionRule
{
	InstructionRuleCCTLL(): InstructionRule("CCTLL", 1, true, false)
	{
		hpBinaryStringToOpcode8("1010 000000 1110 000000 000000 000000000000000000000000 00000000 001011", OpcodeWord0, OpcodeWord1);
		SetOperands(2,
					&OPRRegister0,
					&OPRGlobalMemoryWithLastWithoutLast2Bits);
		ModifierGroups[0].Initialize(false, 8,
									&MRCCTLOp2QRY1,
									&MRCCTLOp2PF1,
									&MRCCTLOp2PF1_5,
									&MRCCTLOp2PR2,
									&MRCCTLOp2WB,
									&MRCCTLOp2IV,
									&MRCCTLOp2IVALL,
									&MRCCTLOp2RS);
	}
}IRCCTLL;