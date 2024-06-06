/* Hiep Tran - PrintJob.h - CS010C */

#pragma once

class PrintJob {
    public: 
        PrintJob(int priority, int jobNum, int numPages); //Default Constructor 
        int getPriority() const; //Accessor function that returns priority
        int getJobNumber() const; //Accessor function that returns jobNumber
        int getPages() const; //Accessor function that returns numPages
    private:
        int priority;
        int jobNumber;
        int numPages;
};