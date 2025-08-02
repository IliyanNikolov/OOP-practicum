#ifndef TOURIST_AGENCY_SYSTEM_HEADER
#define TOURIST_AGENCY_SYSTEM_HEADER

#include"HistoricalLandmark.h"
#include"NaturalLandmark.h"
#include"ExternalUser.h"
#include"EmployeeUser.h"

class AgencySystem{
private:
    std::string externalUsersFileName;
    std::string employeeUsersFileName;
    std::vector<ExternalUser> externalUsers;
    std::vector<Employee> employeeUsers;
    

public:
    AgencySystem() = default;




};





#endif