//  SQLiteWrapper.h
//  Created by Ashley Ramsey on 4/06/11.
//  Copyright 2011 ashramsey. All rights reserved.

#import <Foundation/Foundation.h>
#import <sqlite3.h>

static NSString * const kSQLiteWrapperVersion = @"1.0";

@interface SQLiteWrapper : NSObject <NSFastEnumeration> {
    sqlite3 *database;
    sqlite3_stmt *statement;
    NSString *tableName;
    NSString *databaseFileName;
    NSFileManager *filemanager;
    
    // for "fast enumeration" (iterator/generator pattern)
    NSDictionary * enumRows[1]; // enumerated (iterator) object(s) are passed in a C array
                                // we only ever pass one at a time
}

@property (nonatomic, retain) NSString *tableName;

// object management
- (SQLiteWrapper *) initWithDBFilename: (NSString *) fn;
- (SQLiteWrapper *) initWithDBFilename: (NSString *) fn andTableName: (NSString *) tn;
- (void) openDB;
- (void) closeDB;
- (NSString *) getVersion;
- (NSString *) getDBPath;

// SQL queries
- (NSNumber *) doQuery:(NSString *) query, ...;
- (SQLiteWrapper *) getQuery:(NSString *) query, ...;
- (void) prepareQuery:(NSString *) query, ...;
- (id) valueFromQuery:(NSString *) query, ...;

// CRUD methods
- (NSNumber *) insertRow:(NSDictionary *) record;
- (void) updateRow:(NSDictionary *) record: (NSNumber *) rowID;
- (void) deleteRow:(NSNumber *) rowID;
- (NSDictionary *) getRow: (NSNumber *) rowID;
- (NSNumber *) countRows;

// Raw results
- (void) bindSQL:(const char *) cQuery arguments:(va_list)args;
- (NSDictionary *) getPreparedRow;
- (id) getPreparedValue;

// Utilities
- (id) columnValue:(int) columnIndex;
- (NSNumber *) lastInsertId;

@end
