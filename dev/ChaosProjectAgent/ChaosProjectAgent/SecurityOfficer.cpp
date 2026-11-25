#include "SecurityOfficer.h"
#include "Facility.h"
#include <iostream>
// Initialize the shared Staff properties.
SecurityOfficer::SecurityOfficer(
	int staff_id, 
	std::string staff_name, 
	int hiring_cost, 
	int skill_level)
	: Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}
// Display the SecurityOfficer's assigned duty.
void SecurityOfficer::performDuty()
{
	std::cout << getStaffName()
		<< " is monitoring facility security. Skill Level: "
		<< getSkillLevel() << '\n';
}
// Restore Facility Stability based on the officer's skill level.
void SecurityOfficer::respondToSecurityThreat(Facility& facility)
{
	facility.adjustFacilityStability(getSkillLevel());
}
