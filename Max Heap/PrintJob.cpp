/* Hiep Tran - PrintJob.cpp - CS010C */

#include "PrintJob.h"

//Default Constructor for PrintJob
PrintJob::PrintJob (int setP, int setJ, int numP) : priority(setP), jobNumber(setJ), numPages(numP) {}

//Accessor function that returns priority
int PrintJob::getPriority() const {
    return priority;
}

//Accessor function that returns jobNumber
int PrintJob::getJobNumber() const {
    return jobNumber;
}

//Accessor function that returns numPages
int PrintJob::getPages() const {
    return numPages;
}