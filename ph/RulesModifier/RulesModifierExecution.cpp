
#include "../DataTypes.h"
#include "../helper/helperMixed.h"

#include "../stdafx.h"
//#include "stdafx.h" //SMark

#include "RulesModifierExecution.h"


struct ModifierRuleCALNOINC: ModifierRule
{
	ModifierRuleCALNOINC(): ModifierRule("NOINC", true, false, false)
	{
		hpBinaryStringToOpcode4("11111111111111110111111111111111", Mask0);
		Bits0 = 0;
	}
}MRCALNOINC;

struct ModifierRuleBRAU: ModifierRule
{
	ModifierRuleBRAU(): ModifierRule("U", true, false, false)
	{
		hpBinaryStringToOpcode4("11111111111111101111111111111111", Mask0);
		Bits0 = 1<<15;
	}
}MRBRAU;

struct ModifierRuleNOPTRIG: ModifierRule
{
	ModifierRuleNOPTRIG(): ModifierRule("TRIG", false, true, false)
	{
		Mask1 = 0xffffffff;
		Bits1 = 1 << 18;
	}
}MRNOPTRIG;

struct ModifierRuleNOPOP: ModifierRule
{
	ModifierRuleNOPOP(int type): ModifierRule("", false, true, false)
	{
		hpBinaryStringToOpcode4("11 11111111 11111111 10000111 111111", Mask1);
		Bits1 = type<<19;
		if(type==1)
			Name = "FMA64";
		else if(type == 2)
			Name = "FMA32";
		else if(type == 3)
			Name = "XLU";
		else if(type == 4)
			Name = "ALU";
		else if(type == 5)
			Name = "AGU";
		else if(type == 6)
			Name = "SU";
		else if(type == 7)
			Name = "FU";
		else if(type == 8)
			Name = "FMUL";
	}
}	MRNOPFMA64(1),
	MRNOPFMA32(2),
	MRNOPXLU  (3),
	MRNOPALU  (4),
	MRNOPAGU  (5),
	MRNOPSU   (6),
	MRNOPFU   (7),
	MRNOPFMUL (8);
struct ModifierRuleMEMBAR: ModifierRule
{
	ModifierRuleMEMBAR(int type): ModifierRule("", true, false, false)
	{
		hpBinaryStringToOpcode4("1111 100111 1111 111111 111111 111111", Mask0);
		Bits0 = type << 5;
		if(type==0)
			Name = "CTA";
		else if(type == 1)
			Name = "GL";
		else if(type == 2)
			Name = "SYS";
		else throw exception();
	}
}MRMEMBARCTA(0), MRMEMBARGL(1), MRMEMBARSYS(2);

struct ModifierRuleATOM: ModifierRule
{
	ModifierRuleATOM(int type): ModifierRule("", true, false, false)
	{
		Mask0 = 0xfffffe1f;
		Bits0 = type << 5;
		if(type==0)
			Name = "ADD";
		else if(type==1)
			Name = "MIN";
		else if(type==2)
			Name = "MAX";
		else if(type==3)
			Name = "INC";
		else if(type==4)
			Name = "DEC";
		else if(type==5)
			Name = "AND";
		else if(type==6)
			Name = "OR";
		else if(type==7)
			Name = "XOR";
		else if(type==8)
			Name = "EXCH";
		else if(type==9)
			Name = "CAS";
		else throw exception();
	}				
}	MRATOMADD(0),	
	MRATOMMIN(1),
	MRATOMMAX(2),
	MRATOMINC(3),
	MRATOMDEC(4),
	MRATOMAND(5),
	MRATOMOR(6),
	MRATOMXOR(7),
	MRATOMEXCH(8),
	MRATOMCAS(9);

struct ModifierRuleATOMType: ModifierRule
{
	ModifierRuleATOMType(int type, SubString name): ModifierRule("", true, true, false)
	{
		Mask0 = 0xfffffdff;
		Mask1 = 0xc7ffffff;
		Bits0 = (type&0x1)<<9;
		Bits1 = (type&0xe)<<26;
		Name = name;
	}
}	MRATOMTypeU64(5, "U64"),
	MRATOMTypeS32(7, "S32"),
	MRATOMTypeF32(11,"F32");

struct ModifierRuleATOMIgnored: ModifierRule
{
	ModifierRuleATOMIgnored(SubString name): ModifierRule("", false, false, false)
	{
		Name = name;
	}
}MRATOMIgnoredFTZ("FTZ"), MRATOMIgnoredRN("RN");


struct ModifierRuleVOTE: ModifierRule
{
	ModifierRuleVOTE(int type): ModifierRule("", true, false, false)
	{
		Mask0 = 0xffffff1f;
		Bits0 = type<<5;
		if(type==0)
			Name = "ALL";
		else if(type==1)
			Name = "ANY";
		else if(type == 2)
			Name = "EQ";
		else if(type==5)
			Name = "VTG";
		else
			throw exception();
	}
}MRVOTEALL(0), MRVOTEANY(1), MRVOTEEQ(2), MRVOTEVTG(5);

struct ModifierRuleVOTEVTG: ModifierRule
{
	ModifierRuleVOTEVTG(int type): ModifierRule("", true, false, false)
	{
		Mask0 = 0xffffff9f;
		Bits0 = type<<5;
		if(type==1)
			Name = "R";
		else if(type == 2)
			Name = "A";
		else if(type == 3)
			Name = "RA";
		else throw exception();
	}
}MRVOTEVTGR(1), MRVOTEVTGA(2), MRVOTEVTGRA(3);