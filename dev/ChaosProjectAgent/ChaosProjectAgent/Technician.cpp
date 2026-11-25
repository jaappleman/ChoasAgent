#include "Technician.h"
#include "Facility.h"
#include <iostream>
// Initialize the shared Staff properties.
Technician::Technician(
	int staff_id, 
	std::string staff_name, 
	int hiring_cost, 
	int skill_level)
	: Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}
// Display the Technician's assigned duty.
void Technician::performDuty()
{
	std::cout << getStaffName()
		<< " is maintaining facility systems. Skill Level: "
		<< getSkillLevel() << '\n';
}
// Restore facility power based on the technician's skill level.
void Technician::restorePower(Facility& facility)
{
	facility.adjustPower(getSkillLevel());
}
