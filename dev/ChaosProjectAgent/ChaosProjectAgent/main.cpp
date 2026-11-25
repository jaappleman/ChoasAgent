#include <iostream>
#include "Helper.h"
#include "Anomaly.h"
#include "Facility.h"
#include "Researcher.h"
#include "Technician.h"
#include "ContainmentSpecialist.h"
#include "SecurityOfficer.h"
#include "MedicalOfficer.h"

// Core facility system tests
void testAnomalyMaintenance(int& tests_passed, int& tests_failed);
void testResearchSystem(int& tests_passed, int& tests_failed);

// Staff specialization tests
void testResearcher(int& tests_passed, int& tests_failed);
void testTechnician(int& tests_passed, int& tests_failed);
void testContainmentSpecialist(int& tests_passed, int& tests_failed);
void testSecurityOfficer(int& tests_passed, int& tests_failed);
void testMedicalOfficer(int& tests_passed, int& tests_failed);

// Test utility
void recordTestResult(bool test_passed, int& tests_passed, int& tests_failed);

int main()
{
	// ==========================================
	//                TITLE BANNERS
	// ==========================================
	Helper::AnomalyBanner();
	Helper::AnomalySymbol();

	std::cout << "\n\nThings are about to get really, really weird. Welcome to "
		<< Helper::BLINK << Helper::SCARLET << "Anomaly//Containment"
		<< Helper::RESET << ".\n\n";


	// ==========================================
	//              FACILITY TESTING
	// ==========================================

	// Shared counters track results across all test suites.
	int tests_passed = 0;
	int tests_failed = 0;

	// ==========================================
	//           FACILITY SYSTEM TESTS
	// ==========================================

	testAnomalyMaintenance(tests_passed, tests_failed);
	testResearchSystem(tests_passed, tests_failed);


	// ==========================================
	//        STAFF SPECIALIZATION TESTS
	// ==========================================

	testResearcher(tests_passed, tests_failed);
	testTechnician(tests_passed, tests_failed);
	testContainmentSpecialist(tests_passed, tests_failed);
	testSecurityOfficer(tests_passed, tests_failed);
	testMedicalOfficer(tests_passed, tests_failed);


	// ==========================================
	//                TEST SUMMARY
	// ==========================================

	std::cout << "\n========== TEST SUMMARY ==========\n";
	std::cout << "Tests Passed: " << tests_passed << '\n';
	std::cout << "Tests Failed: " << tests_failed << '\n';
	std::cout << "Total Tests: " << tests_passed + tests_failed << '\n';
	std::cout << "==================================\n";

	return 0;
}

void testAnomalyMaintenance(int& tests_passed, int& tests_failed)
{
	std::cout << "\n========== ANOMALY MAINTENANCE TESTS ==========\n";

	bool test_passed = false;

	// --------------------------------------------------
	// SUCCESSFUL MAINTENANCE
	// Verify that maintenance deducts the correct resources
	// and increases the selected anomaly's stability.
	// --------------------------------------------------

	Facility facility;

	std::cout << "Credits Before: " << facility.getCredits() << '\n';
	std::cout << "Power Before: " << facility.getPower() << '\n';

	bool success = facility.performAnomalyMaintenance(3, 25);

	Anomaly* anomaly = facility.findAnomalyById(3);

	test_passed = success
		&& anomaly != nullptr
		&& facility.getCredits() == 450
		&& facility.getPower() == 90
		&& anomaly->getStability() == 45;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Successful Maintenance\n";

	std::cout << "Maintenance Successful: " << success << '\n';
	std::cout << "Credits After: " << facility.getCredits() << '\n';
	std::cout << "Power After: " << facility.getPower() << '\n';

	facility.displayAnomalies();


	// --------------------------------------------------
	// INSUFFICIENT CREDITS
	// Verify that maintenance fails when the Facility
	// cannot afford it, without deducting any resources.
	// --------------------------------------------------

	std::cout << "\n--- INSUFFICIENT CREDITS TEST ---\n";

	Facility poor_facility;

	poor_facility.adjustCredits(-470);

	bool poor_success = poor_facility.performAnomalyMaintenance(3, 25);

	Anomaly* poor_anomaly = poor_facility.findAnomalyById(3);

	test_passed = !poor_success
		&& poor_anomaly != nullptr
		&& poor_facility.getCredits() == 30
		&& poor_facility.getPower() == 100
		&& poor_anomaly->getStability() == 20;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Insufficient Credits\n";

	std::cout << "Credits After: " << poor_facility.getCredits() << '\n';
	std::cout << "Maintenance Successful: " << poor_success << '\n';


	// --------------------------------------------------
	// INSUFFICIENT POWER
	// Verify that maintenance fails when the Facility
	// does not have enough power, preserving all resources.
	// --------------------------------------------------

	std::cout << "\n--- INSUFFICIENT POWER TEST ---\n";

	Facility low_power_facility;

	low_power_facility.adjustPower(-95);

	bool power_success = low_power_facility.performAnomalyMaintenance(3, 25);

	Anomaly* low_power_anomaly = low_power_facility.findAnomalyById(3);

	test_passed = !power_success
		&& low_power_anomaly != nullptr
		&& low_power_facility.getCredits() == 500
		&& low_power_facility.getPower() == 5
		&& low_power_anomaly->getStability() == 20;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Insufficient Power\n";

	std::cout << "Credits After: " << low_power_facility.getCredits() << '\n';
	std::cout << "Power After: " << low_power_facility.getPower() << '\n';
	std::cout << "Maintenance Successful: " << power_success << '\n';


	// --------------------------------------------------
	// INVALID ANOMALY ID
	// Verify that maintenance fails when the requested
	// anomaly does not exist, without spending resources.
	// --------------------------------------------------

	std::cout << "\n--- INVALID ANOMALY ID TEST ---\n";

	Facility invalid_facility;

	bool invalid_success = invalid_facility.performAnomalyMaintenance(99, 25);

	Anomaly* invalid_anomaly = invalid_facility.findAnomalyById(3);

	test_passed = !invalid_success
		&& invalid_anomaly != nullptr
		&& invalid_facility.getCredits() == 500
		&& invalid_facility.getPower() == 100
		&& invalid_anomaly->getStability() == 20;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Invalid Anomaly ID\n";

	std::cout << "Credits After: " << invalid_facility.getCredits() << '\n';
	std::cout << "Power After: " << invalid_facility.getPower() << '\n';
	std::cout << "Maintenance Successful: " << invalid_success << '\n';


	// --------------------------------------------------
	// STABILITY CAP
	// Verify that maintenance cannot increase anomaly
	// stability beyond the maximum value of 100.
	// --------------------------------------------------

	std::cout << "\n--- STABILITY CAP TEST ---\n";

	Facility cap_facility;

	bool cap_success = cap_facility.performAnomalyMaintenance(1, 25);

	Anomaly* cap_anomaly = cap_facility.findAnomalyById(1);

	test_passed = cap_success
		&& cap_anomaly != nullptr
		&& cap_facility.getCredits() == 450
		&& cap_facility.getPower() == 90
		&& cap_anomaly->getStability() == 100;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Stability Cap\n";

	if (cap_anomaly != nullptr)
	{
		std::cout << "Whispering Archive Stability: "
			<< cap_anomaly->getStability() << '\n';
	}


	// --------------------------------------------------
	// STABILITY FLOOR
	// Verify that reducing anomaly stability cannot
	// take its value below the minimum of 0.
	// --------------------------------------------------

	std::cout << "\n--- STABILITY FLOOR TEST ---\n";

	Facility floor_facility;

	Anomaly* floor_anomaly = floor_facility.findAnomalyById(3);

	test_passed = floor_anomaly != nullptr;

	if (test_passed)
	{
		floor_anomaly->adjustStability(-50);

		test_passed = floor_anomaly->getStability() == 0;
	}

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Stability Floor\n";

	if (floor_anomaly != nullptr)
	{
		std::cout << "Forgotten Signal Stability: "
			<< floor_anomaly->getStability() << '\n';
	}
}

void testResearchSystem(int& tests_passed, int& tests_failed)
{
	std::cout << "\n========== RESEARCH SYSTEM TESTS ==========\n";

	// Create a Facility to test the shared research point pool.
	Facility research_facility;

	bool test_passed = false;

	// --------------------------------------------------
	// INITIAL RESEARCH BALANCE
	// Verify that a newly created Facility starts with 0 research points.
	// --------------------------------------------------

	test_passed = research_facility.getResearchPoints() == 0;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Initial Research Balance\n";

	std::cout << "Initial Research Points: "
		<< research_facility.getResearchPoints() << '\n';


	// --------------------------------------------------
	// ADD RESEARCH POINTS
	// Verify that valid research contributions increase the balance.
	// --------------------------------------------------

	std::cout << "\n--- ADD RESEARCH POINTS TEST ---\n";

	research_facility.addResearchPoints(50);

	test_passed = research_facility.getResearchPoints() == 50;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Add Research Points\n";

	std::cout << "Research Points After Addition: "
		<< research_facility.getResearchPoints() << '\n';


	// --------------------------------------------------
	// INVALID RESEARCH CONTRIBUTIONS
	// Verify that zero and negative contributions are rejected.
	// The existing balance should remain unchanged.
	// --------------------------------------------------

	std::cout << "\n--- INVALID RESEARCH CONTRIBUTION TEST ---\n";

	research_facility.addResearchPoints(0);
	research_facility.addResearchPoints(-20);

	test_passed = research_facility.getResearchPoints() == 50;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Invalid Research Contributions\n";

	std::cout << "Research Points After Invalid Contributions: "
		<< research_facility.getResearchPoints() << '\n';


	// --------------------------------------------------
	// SPEND RESEARCH POINTS
	// Verify that a valid purchase deducts the correct amount.
	// --------------------------------------------------

	std::cout << "\n--- SPEND RESEARCH POINTS TEST ---\n";

	test_passed = research_facility.spendResearchPoints(20)
		&& research_facility.getResearchPoints() == 30;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Spend Research Points\n";

	std::cout << "Research Points After Spending: "
		<< research_facility.getResearchPoints() << '\n';


	// --------------------------------------------------
	// INSUFFICIENT RESEARCH POINTS
	// Verify that spending more than the available balance fails.
	// The balance must remain unchanged.
	// --------------------------------------------------

	std::cout << "\n--- INSUFFICIENT RESEARCH POINTS TEST ---\n";

	test_passed = !research_facility.spendResearchPoints(40)
		&& research_facility.getResearchPoints() == 30;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Insufficient Research Points\n";

	std::cout << "Research Points After Failed Spending: "
		<< research_facility.getResearchPoints() << '\n';


	// --------------------------------------------------
	// INVALID RESEARCH SPENDING
	// Verify that zero and negative spending amounts are rejected.
	// --------------------------------------------------

	std::cout << "\n--- INVALID RESEARCH SPENDING TEST ---\n";

	research_facility.spendResearchPoints(0);
	research_facility.spendResearchPoints(-10);

	test_passed = research_facility.getResearchPoints() == 30;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Invalid Research Spending\n";

	std::cout << "Research Points After Invalid Spending: "
		<< research_facility.getResearchPoints() << '\n';
}


void testResearcher(int& tests_passed, int& tests_failed)
{
	std::cout << "\n========== RESEARCHER TESTS ==========\n";

	// Create a Facility and a Researcher.
	Facility facility;
	Researcher researcher(101, "Dr. Voss", 200, 5);

	// Test polymorphism through a base-class pointer.
	Staff* staff_ptr = &researcher;
	staff_ptr->performDuty();

	// Record the initial research balance.
	int research_before = facility.getResearchPoints();

	// Have the Researcher conduct research.
	researcher.conductResearch(facility);

	// Verify that research points increased by the Researcher's skill level.
	bool test_passed = facility.getResearchPoints()
		== research_before + researcher.getSkillLevel();

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Researcher Contribution\n";

	std::cout << "Research Points Before: "
		<< research_before << '\n';

	std::cout << "Research Points After: "
		<< facility.getResearchPoints() << '\n';
}



void testTechnician(int& tests_passed, int& tests_failed)
{
	std::cout << "\n========== TECHNICIAN TESTS ==========\n";

	// Create a Facility and a Technician.
	Facility facility;
	Technician technician(103, "Morgan Hale", 150, 8);

	// Test polymorphism through a base-class pointer.
	Staff* staff_ptr = &technician;
	staff_ptr->performDuty();

	// Record the Facility's original power level.
	int power_before = facility.getPower();

	// Have the Technician restore power.
	technician.restorePower(facility);

	// Verify that power increased by the Technician's skill level.
	bool test_passed = facility.getPower()
		== power_before + technician.getSkillLevel();

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Technician Power Restoration\n";

	std::cout << "Power Before: " << power_before << '\n';
	std::cout << "Power After: " << facility.getPower() << '\n';
}



void testContainmentSpecialist(int& tests_passed, int& tests_failed)
{
	std::cout << "\n========== CONTAINMENT SPECIALIST TESTS ==========\n";

	// Create a Facility and a ContainmentSpecialist.
	Facility facility;

	ContainmentSpecialist specialist(201, "Morgan Hale", 200, 8);

	// Test the specialist's assigned duty.
	specialist.performDuty();

	// Retrieve the anomaly that will receive maintenance.
	Anomaly* anomaly = facility.findAnomalyById(3);

	// Record its original stability.
	int stability_before = anomaly->getStability();

	// Apply the specialist's maintenance ability.
	specialist.stabilizeAnomaly(facility, 3);

	// Verify that stability increased by the specialist's skill level.
	bool test_passed = anomaly->getStability() == stability_before + 8;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Containment Specialist Stabilization\n";

	std::cout << "Stability Before: " << stability_before << '\n';
	std::cout << "Stability After: " << anomaly->getStability() << '\n';


	// --------------------------------------------------
	// STABILITY CAP TEST
	// Verify that specialist maintenance cannot exceed 100% stability.
	// --------------------------------------------------

	std::cout << "\n--- CONTAINMENT STABILITY CAP TEST ---\n";

	Facility cap_facility;

	ContainmentSpecialist cap_specialist(202, "Elena Cross", 200, 20);

	// Find the anomaly that starts at 85% stability.
	Anomaly* cap_anomaly = cap_facility.findAnomalyById(1);

	// Apply 20 points of stabilization.
	// The expected result is 100%, not 105%.
	cap_specialist.stabilizeAnomaly(cap_facility, 1);

	test_passed = cap_anomaly != nullptr
		&& cap_anomaly->getStability() == 100;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Containment Stability Cap\n";

	if (cap_anomaly != nullptr)
	{
		std::cout << "Final Stability: "
			<< cap_anomaly->getStability() << '\n';
	}


	// --------------------------------------------------
	// INVALID ANOMALY ID TEST
	// Verify that stabilization safely handles missing anomalies.
	// --------------------------------------------------

	std::cout << "\n--- INVALID ANOMALY ID TEST ---\n";

	Facility invalid_facility;

	ContainmentSpecialist invalid_specialist(
		203, "Elena Cross", 200, 8
	);

	// Attempt to stabilize an anomaly that does not exist.
	invalid_specialist.stabilizeAnomaly(invalid_facility, 99);

	// Verify that existing anomalies remain unchanged.
	Anomaly* existing_anomaly = invalid_facility.findAnomalyById(3);

	test_passed = existing_anomaly != nullptr
		&& existing_anomaly->getStability() == 20;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Invalid Anomaly ID\n";
	
}

void testSecurityOfficer(int& tests_passed, int& tests_failed)
{
	std::cout << "\n========== SECURITY OFFICER TESTS ==========\n";

	// Create a Facility and a SecurityOfficer.
	Facility facility;

	SecurityOfficer officer(301, "Alex Mercer", 200, 8);

	// Display the officer's assigned duty.
	officer.performDuty();

	// Lower stability to create room for the security response.
	facility.adjustFacilityStability(-35);
	// Record the Facility's original stability.
	int stability_before = facility.getFacilityStability();

	// Respond to a security threat.
	officer.respondToSecurityThreat(facility);

	// Verify that stability increased by the officer's skill level.
	bool test_passed = facility.getFacilityStability()
		== stability_before + 8;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Security Threat Response\n";

	std::cout << "Stability Before: " << stability_before << '\n';
	std::cout << "Stability After: "
		<< facility.getFacilityStability() << '\n';

	// ==========================================
	//          SECURITY STABILITY CAP TEST
	// ==========================================

	std::cout << "\n--- SECURITY STABILITY CAP TEST ---\n";

	// Create a separate Facility for this test.
	Facility cap_facility;

	// Create an officer with a skill level of 20.
	SecurityOfficer cap_officer(302, "Elena Cross", 200, 20);

	// Set Facility Stability to 95.
	cap_facility.adjustFacilityStability(-5);

	// Attempt to restore another 20 stability points.
	cap_officer.respondToSecurityThreat(cap_facility);

	// Verify that stability never exceeds 100.
	test_passed = cap_facility.getFacilityStability() == 100;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Security Stability Cap\n";

	std::cout << "Final Stability: "
		<< cap_facility.getFacilityStability() << '\n';
}


void testMedicalOfficer(int& tests_passed, int& tests_failed)
{
	std::cout << "\n========== MEDICAL OFFICER TESTS ==========\n";

	// Create a MedicalOfficer and a Researcher.
	MedicalOfficer medical_officer(401, "Dr. Evelyn Hart", 250, 12);
	Researcher researcher(101, "Dr. Voss", 200, 5);

	// Reduce the researcher's condition to simulate fatigue.
	researcher.adjustStaffCondition(-40);

	// Record the researcher's original condition.
	int condition_before = researcher.getStaffCondition();

	// Display the MedicalOfficer's assigned duty.
	medical_officer.performDuty();

	// Treat the researcher.
	medical_officer.treatStaff(researcher);

	// Verify that condition increased by the MedicalOfficer's skill level.
	bool test_passed = researcher.getStaffCondition()
		== condition_before + 12;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Medical Treatment\n";

	std::cout << "Condition Before: " << condition_before << '\n';
	std::cout << "Condition After: "
		<< researcher.getStaffCondition() << '\n';

	// ==========================================
//           MEDICAL CONDITION CAP TEST
// ==========================================

	std::cout << "\n--- MEDICAL CONDITION CAP TEST ---\n";

	// Create a separate MedicalOfficer and Technician.
	MedicalOfficer cap_medical_officer(402, "Dr. Sarah Chen", 250, 20);
	Technician technician(102, "Morgan Hale", 200, 8);

	// Set the Technician's condition to 95.
	technician.adjustStaffCondition(-5);

	// Treat the Technician.
	cap_medical_officer.treatStaff(technician);

	// Verify that condition does not exceed 100.
	test_passed = technician.getStaffCondition() == 100;

	recordTestResult(test_passed, tests_passed, tests_failed);

	std::cout << (test_passed ? "PASS" : "FAIL")
		<< " | Medical Condition Cap\n";

	std::cout << "Final Condition: "
		<< technician.getStaffCondition() << '\n';
}

// Updates the appropriate test counter based on the test result.
void recordTestResult(bool test_passed, int& tests_passed, int& tests_failed)
{
	if (test_passed)
	{
		tests_passed++;
	}
	else
	{
		tests_failed++;
	}
}