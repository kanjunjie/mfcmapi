#pragma once
#include "SmartViewParser.h"

struct FolderFieldDefinitionCommon
{
	GUID PropSetGuid;
	DWORD fcapm;
	DWORD dwString;
	DWORD dwBitmap;
	DWORD dwDisplay;
	DWORD iFmt;
	WORD wszFormulaLength;
	LPWSTR wszFormula;
};

struct FolderFieldDefinitionA
{
	DWORD FieldType;
	WORD FieldNameLength;
	LPSTR FieldName;
	FolderFieldDefinitionCommon Common;
};

struct FolderFieldDefinitionW
{
	DWORD FieldType;
	WORD FieldNameLength;
	LPWSTR FieldName;
	FolderFieldDefinitionCommon Common;
};

struct FolderUserFieldA
{
	DWORD FieldDefinitionCount;
	FolderFieldDefinitionA* FieldDefinitions;
};

struct FolderUserFieldW
{
	DWORD FieldDefinitionCount;
	FolderFieldDefinitionW* FieldDefinitions;
};

class FolderUserFieldStream : public SmartViewParser
{
public:
	FolderUserFieldStream(ULONG cbBin, _In_count_(cbBin) LPBYTE lpBin);
	~FolderUserFieldStream();

	_Check_return_ LPWSTR ToString();

private:
	void Parse();

	FolderUserFieldA m_FolderUserFieldsAnsi;
	FolderUserFieldW m_FolderUserFieldsUnicode;
};