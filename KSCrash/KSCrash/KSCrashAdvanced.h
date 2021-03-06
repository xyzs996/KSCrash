//
//  KSCrashAdvanced.h
//
//  Created by Karl Stenerud on 2012-05-06.
//
//  Copyright (c) 2012 Karl Stenerud. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//


#import "KSCrash.h"
#import "KSCrashReportStore.h"


/**
 * Advanced interface to the KSCrash system.
 */
@interface KSCrash (Advanced)

/** Store containing all crash reports. */
@property(nonatomic, readwrite, retain) KSCrashReportStore* crashReportStore;

/** Path where the log of KSCrash's activities will be written.
 * If nil, log entries will be printed to the console.
 *
 * This property cannot be set directly. Use one of the "redirectConsoleLogs"
 * methods instead.
 *
 * Default: nil
 */
@property(nonatomic, readonly, retain) NSString* logFilePath;

/** Send the specified reports to the current sink.
 *
 * @param reports The reports to send.
 * @param onCompletion Called when sending is complete (nil = ignore).
 */
- (void) sendReports:(NSArray*) reports onCompletion:(KSCrashReportFilterCompletion) onCompletion;

/** The total number of unsent reports. Note: This is an expensive operation.
 */
- (NSUInteger) reportCount;

/** Get all reports, with data types corrected, as dictionaries.
 */
- (NSArray*) allReports;

/** Sets logFilePath to the default log file location
 * (Library/Caches/KSCrashReports/<bundle name>-CrashLog.txt).
 * If the file exists, it will be overwritten.
 *
 * @return true if the operation was successful.
 */
- (BOOL) redirectConsoleLogsToDefaultFile;

/** Redirect the log of KSCrash's activities from the console to the specified log file.
 *
 * @param fullPath The path to the logfile (nil = log to console instead).
 * @param overwrite If true, overwrite the file (ignored if fullPath is nil).
 *
 * @return true if the operation was successful.
 */
- (BOOL) redirectConsoleLogsToFile:(NSString*) fullPath overwrite:(BOOL) overwrite;

@end

