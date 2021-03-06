/**********************************************************************
// @@@ START COPYRIGHT @@@
//
// (C) Copyright 1998-2014 Hewlett-Packard Development Company, L.P.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
// @@@ END COPYRIGHT @@@
********************************************************************/
/**************************************************************************
**************************************************************************/
//
// MODULE: SrvrKds.h
//
// PURPOSE:
//     
//
//

#ifndef _SRVRKDS_DEFINED
#define _SRVRKDS_DEFINED
#include "odbcCommon.h"

namespace SRVR {

extern void kdsCreateSQLDescSeq(SQLItemDescList_def *SQLDesc, short numEntries);
extern void kdsCreateEmptySQLDescSeq(SQLItemDescList_def *SQLDesc);
extern void kdsCopyToSQLDescSeq(SQLItemDescList_def *SQLDesc, 
				  char *DescName,
				  long DataType,  
				  long DateTimeCode, long Length, 
				  long Precision, long scale,
				  long Nullable,
				  long ODBCDataType, 
				  long ODBCPrecision, BOOL SignType,
				  long SQLCharset, long ODBCCharset,
				  char* TableName,
				  char* CatalogName,
				  char* SchemaName,
				  char* Heading,
				  long intLeadPrec,
				  long paramMode);
extern void kdsCreateSQLErrorException(	
								bool& bSQLMessageSet,
								odbc_SQLSvc_SQLError *SQLError, 
								long numConditions);
extern void kdsCopySQLErrorException(
								odbc_SQLSvc_SQLError *SQLError, 
								char *msg_buf,
								long sqlcode,
								char *sqlState);

extern void kdsCopySQLErrorExceptionAndRowCount(
								odbc_SQLSvc_SQLError *SQLError, 
								char *msg_buf,
								long sqlcode,
								char *sqlState,
								long currentRowCount);

extern void kdsCopyToSQLValueSeq(SQLValueList_def *SQLValueList,
							 IDL_long dataType, 
							 IDL_short indValue, 
							 void *varPtr, 
							 long allocLength,
							 long Charset);
long kdsCopyToSMDSQLValueSeq(SQLValueList_def *SQLValueList,
							 IDL_long dataType, 
							 IDL_short indValue, 
							 char *dataValue, 
							 long allocLength,
							 long Charset);

void kdsCopyRGErrorException(
							odbc_SQLSvc_SQLError *SQLError, 
							RES_HIT_DESC_def *rgPolicyHit);

void kdsCreateSQLWarningException(
							bool& bSQLMessageSet,
							ERROR_DESC_LIST_def *SQLWarning, 
							long numConditions);
void kdsCopyRGWarningException(ERROR_DESC_LIST_def *SQLWarning, 
							RES_HIT_DESC_def *rgPolicyHit);

extern void kdsCopyToSQLDataSeq(SQL_DataValue_def *outputDataValue,
							 IDL_long dataType, 
							 IDL_short indValue, 
							 void *varPtr, 
							 long allocLength,
							 long Charset);

void CopyRGMsg(	ERROR_DESC_def *SqlErrorDesc, 
				RES_HIT_DESC_def *rgPolicyHit);
}

#endif
