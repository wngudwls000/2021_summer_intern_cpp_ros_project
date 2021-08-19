#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization()
{
    long idle = LinuxParser::IdleJiffies();
    long active = LinuxParser::ActiveJiffies();
    utilization = static_cast<float>(active - prev_active) / (idle - prev_idle + active - prev_active);
    prev_idle = idle;
    prev_active = active;
    return utilization;
}