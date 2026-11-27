#include "Testing.h"

#include <iostream>
#include <memory>

#include "Facility.h"
#include "Anomaly.h"
#include "Researcher.h"
#include "Technician.h"
#include "ContainmentSpecialist.h"
#include "SecurityOfficer.h"
#include "MedicalOfficer.h"

namespace Testing
{
	// ============================================================
	//                  CORE FACILITY SYSTEM TESTS
	// ============================================================

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

		Anomaly* anomaly = facility.findAnomalyById(3);

		int credits_before = facility.getCredits();
		int power_before = facility.getPower();
		int stability_before = anomaly != nullptr
			? anomaly->getStability()
			: -1;

		bool maintenance_success = facility.performAnomalyMaintenance(3, 25);

		test_passed = maintenance_success
			&& anomaly != nullptr
			&& facility.getCredits() == credits_before - 50
			&& facility.getPower() == power_before - 10
			&& anomaly->getStability() == stability_before + 25;

		recordTestResult(
			test_passed,
			"Successful Maintenance",
			tests_passed,
			tests_failed
		);

		std::cout << "Maintenance Successful: "
			<< maintenance_success << '\n';

		std::cout << "Credits: "
			<< credits_before << " -> " << facility.getCredits() << '\n';

		std::cout << "Power: "
			<< power_before << " -> " << facility.getPower() << '\n';

		if (anomaly != nullptr)
		{
			std::cout << "Anomaly Stability: "
				<< stability_before << " -> "
				<< anomaly->getStability() << '\n';
		}



		// --------------------------------------------------
		// INSUFFICIENT CREDITS
		// Verify that maintenance fails when the Facility
		// cannot afford it, without changing any resources
		// or anomaly stability.
		// --------------------------------------------------

		std::cout << "\n--- INSUFFICIENT CREDITS TEST ---\n";

		Facility poor_facility;

		// Reduce available credits below the maintenance cost.
		poor_facility.adjustCredits(-1470);

		Anomaly* poor_anomaly = poor_facility.findAnomalyById(3);

		int poor_credits_before = poor_facility.getCredits();
		int poor_power_before = poor_facility.getPower();

		int poor_stability_before = poor_anomaly != nullptr
			? poor_anomaly->getStability()
			: -1;

		bool poor_maintenance_success =
			poor_facility.performAnomalyMaintenance(3, 25);

		test_passed = !poor_maintenance_success
			&& poor_anomaly != nullptr
			&& poor_facility.getCredits() == poor_credits_before
			&& poor_facility.getPower() == poor_power_before
			&& poor_anomaly->getStability() == poor_stability_before;

		recordTestResult(
			test_passed,
			"Insufficient Credits",
			tests_passed,
			tests_failed
		);

		std::cout << "Maintenance Successful: "
			<< poor_maintenance_success << '\n';

		std::cout << "Credits: "
			<< poor_credits_before << " -> "
			<< poor_facility.getCredits() << '\n';

		std::cout << "Power: "
			<< poor_power_before << " -> "
			<< poor_facility.getPower() << '\n';

		if (poor_anomaly != nullptr)
		{
			std::cout << "Anomaly Stability: "
				<< poor_stability_before << " -> "
				<< poor_anomaly->getStability() << '\n';
		}




		// --------------------------------------------------
		// INSUFFICIENT POWER
		// Verify that maintenance fails when the Facility
		// lacks sufficient power, preserving all values.
		// --------------------------------------------------

		std::cout << "\n--- INSUFFICIENT POWER TEST ---\n";

		Facility low_power_facility;

		// Reduce available power below the maintenance cost.
		low_power_facility.adjustPower(-95);

		Anomaly* low_power_anomaly =
			low_power_facility.findAnomalyById(3);

		int low_power_credits_before = low_power_facility.getCredits();
		int low_power_before = low_power_facility.getPower();

		int low_power_stability_before = low_power_anomaly != nullptr
			? low_power_anomaly->getStability()
			: -1;

		bool low_power_maintenance_success =
			low_power_facility.performAnomalyMaintenance(3, 25);

		test_passed = !low_power_maintenance_success
			&& low_power_anomaly != nullptr
			&& low_power_facility.getCredits() == low_power_credits_before
			&& low_power_facility.getPower() == low_power_before
			&& low_power_anomaly->getStability() == low_power_stability_before;

		recordTestResult(
			test_passed,
			"Insufficient Power",
			tests_passed,
			tests_failed
		);

		std::cout << "Maintenance Successful: "
			<< low_power_maintenance_success << '\n';

		std::cout << "Credits: "
			<< low_power_credits_before << " -> "
			<< low_power_facility.getCredits() << '\n';

		std::cout << "Power: "
			<< low_power_before << " -> "
			<< low_power_facility.getPower() << '\n';

		if (low_power_anomaly != nullptr)
		{
			std::cout << "Anomaly Stability: "
				<< low_power_stability_before << " -> "
				<< low_power_anomaly->getStability() << '\n';
		}



		// --------------------------------------------------
		// INVALID ANOMALY ID
		// Verify that maintenance fails when the requested
		// anomaly does not exist, preserving all values.
		// --------------------------------------------------

		std::cout << "\n--- INVALID ANOMALY ID TEST ---\n";

		Facility invalid_facility;

		// Retrieve a valid anomaly to verify that it remains unchanged.
		Anomaly* invalid_anomaly = invalid_facility.findAnomalyById(3);

		int invalid_credits_before = invalid_facility.getCredits();
		int invalid_power_before = invalid_facility.getPower();

		int invalid_stability_before = invalid_anomaly != nullptr
			? invalid_anomaly->getStability()
			: -1;

		// Attempt maintenance using a nonexistent anomaly ID.
		bool invalid_maintenance_success =
			invalid_facility.performAnomalyMaintenance(99, 25);

		test_passed = !invalid_maintenance_success
			&& invalid_anomaly != nullptr
			&& invalid_facility.getCredits() == invalid_credits_before
			&& invalid_facility.getPower() == invalid_power_before
			&& invalid_anomaly->getStability() == invalid_stability_before;

		recordTestResult(
			test_passed,
			"Invalid Anomaly ID",
			tests_passed,
			tests_failed
		);

		std::cout << "Maintenance Successful: "
			<< invalid_maintenance_success << '\n';

		std::cout << "Credits: "
			<< invalid_credits_before << " -> "
			<< invalid_facility.getCredits() << '\n';

		std::cout << "Power: "
			<< invalid_power_before << " -> "
			<< invalid_facility.getPower() << '\n';

		if (invalid_anomaly != nullptr)
		{
			std::cout << "Anomaly Stability: "
				<< invalid_stability_before << " -> "
				<< invalid_anomaly->getStability() << '\n';
		}


		// --------------------------------------------------
		// STABILITY CAP
		// Verify that maintenance cannot increase anomaly
		// stability beyond 100, while still charging resources.
		// --------------------------------------------------

		std::cout << "\n--- STABILITY CAP TEST ---\n";

		Facility cap_facility;

		Anomaly* cap_anomaly = cap_facility.findAnomalyById(1);

		int cap_credits_before = cap_facility.getCredits();
		int cap_power_before = cap_facility.getPower();

		int cap_stability_before = cap_anomaly != nullptr
			? cap_anomaly->getStability()
			: -1;

		bool cap_maintenance_success =
			cap_facility.performAnomalyMaintenance(1, 25);

		test_passed = cap_maintenance_success
			&& cap_anomaly != nullptr
			&& cap_facility.getCredits() == cap_credits_before - 50
			&& cap_facility.getPower() == cap_power_before - 10
			&& cap_anomaly->getStability() == 100;

		recordTestResult(
			test_passed,
			"Stability Cap",
			tests_passed,
			tests_failed
		);

		std::cout << "Maintenance Successful: "
			<< cap_maintenance_success << '\n';

		std::cout << "Credits: "
			<< cap_credits_before << " -> "
			<< cap_facility.getCredits() << '\n';

		std::cout << "Power: "
			<< cap_power_before << " -> "
			<< cap_facility.getPower() << '\n';

		if (cap_anomaly != nullptr)
		{
			std::cout << "Anomaly Stability: "
				<< cap_stability_before << " -> "
				<< cap_anomaly->getStability() << '\n';
		}



		// --------------------------------------------------
		// STABILITY FLOOR
		// Verify that anomaly stability cannot fall below 0.
		// --------------------------------------------------

		std::cout << "\n--- STABILITY FLOOR TEST ---\n";

		Facility floor_facility;

		Anomaly* floor_anomaly = floor_facility.findAnomalyById(3);

		int floor_stability_before = floor_anomaly != nullptr
			? floor_anomaly->getStability()
			: -1;

		// Attempt to reduce stability below zero.
		if (floor_anomaly != nullptr)
		{
			floor_anomaly->adjustStability(-50);
		}

		test_passed = floor_anomaly != nullptr
			&& floor_anomaly->getStability() == 0;

		recordTestResult(
			test_passed,
			"Stability Floor",
			tests_passed,
			tests_failed
		);

		if (floor_anomaly != nullptr)
		{
			std::cout << "Anomaly Stability: "
				<< floor_stability_before << " -> "
				<< floor_anomaly->getStability() << '\n';
		}

	}
    

	// ============================================================
	//                     RESEARCH SYSTEM TESTS
	// ============================================================

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

		recordTestResult(
			test_passed,
			"Initial Research Balance",
			tests_passed,
			tests_failed
		);

		std::cout << "Initial Research Points: "
			<< research_facility.getResearchPoints() << '\n';


		// --------------------------------------------------
		// ADD RESEARCH POINTS
		// Verify that valid research contributions increase the balance.
		// --------------------------------------------------

		std::cout << "\n--- ADD RESEARCH POINTS TEST ---\n";

		research_facility.addResearchPoints(50);

		test_passed = research_facility.getResearchPoints() == 50;

		recordTestResult(
			test_passed,
			"Add Research Points",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Invalid Research Contributions",
			tests_passed,
			tests_failed
		);

		std::cout << "Research Points After Invalid Contributions: "
			<< research_facility.getResearchPoints() << '\n';


		// --------------------------------------------------
		// SPEND RESEARCH POINTS
		// Verify that a valid purchase deducts the correct amount.
		// --------------------------------------------------

		std::cout << "\n--- SPEND RESEARCH POINTS TEST ---\n";

		test_passed = research_facility.spendResearchPoints(20)
			&& research_facility.getResearchPoints() == 30;

		recordTestResult(
			test_passed,
			"Spend Research Points",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Insufficient Research Points",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Invalid Research Spending",
			tests_passed,
			tests_failed
		);

		std::cout << "Research Points After Invalid Spending: "
			<< research_facility.getResearchPoints() << '\n';
	}

	// ============================================================
	//                       STAFF ROSTER TESTS
	// ============================================================

	void testStaffRoster(int& tests_passed, int& tests_failed)
	{
		std::cout << "\n========== STAFF ROSTER TESTS ==========\n";


		// --------------------------------------------------
		// SUCCESSFUL HIRING
		// Verify that hiring adds a staff member to the roster
		// and deducts the correct hiring cost.
		// --------------------------------------------------

		Facility facility;

		int credits_before = facility.getCredits();

		// Create a Researcher and transfer ownership to the Facility.
		bool hiring_success = facility.hireStaff(
			std::make_unique<Researcher>(
				501, "Dr. Helena Voss", 200, 7
			)
		);

		// Verify that hiring succeeded and the correct credits were deducted.
		bool test_passed = hiring_success
			&& facility.getCredits() == credits_before - 200
			&& facility.findStaffById(501) != nullptr;

		recordTestResult(
			test_passed,
			"Successful Staff Hiring",
			tests_passed,
			tests_failed
		);

		std::cout << "Credits Before: " << credits_before << '\n';
		std::cout << "Credits After: " << facility.getCredits() << '\n';

		std::cout << "Staff Found: "
			<< (facility.findStaffById(501) != nullptr) << '\n';

		// --------------------------------------------------
		// INSUFFICIENT CREDITS
		// Verify that hiring fails when the Facility cannot
		// afford the employee, preserving its credit balance.
		// --------------------------------------------------

		std::cout << "\n--- INSUFFICIENT HIRING CREDITS TEST ---\n";

		Facility poor_facility;

		// Reduce available credits below the hiring cost.
		poor_facility.adjustCredits(-1350);

		int poor_credits_before = poor_facility.getCredits();

		bool poor_hiring_success = poor_facility.hireStaff(
			std::make_unique<Researcher>(
				502, "Dr. Elias Reed", 200, 6
			)
		);

		test_passed = !poor_hiring_success
			&& poor_facility.getCredits() == poor_credits_before
			&& poor_facility.findStaffById(502) == nullptr;

		recordTestResult(
			test_passed,
			"Insufficient Hiring Credits",
			tests_passed,
			tests_failed
		);

		std::cout << "Credits Before: "
			<< poor_credits_before << '\n';

		std::cout << "Credits After: "
			<< poor_facility.getCredits() << '\n';

		// --------------------------------------------------
		// DUPLICATE STAFF ID
		// Verify that the Facility rejects a staff member
		// whose ID is already assigned to another employee.
		// --------------------------------------------------

		std::cout << "\n--- DUPLICATE STAFF ID TEST ---\n";

		Facility duplicate_facility;

		// Hire the first staff member.
		bool first_hiring_success = duplicate_facility.hireStaff(
			std::make_unique<Researcher>(
				503, "Dr. Helena Voss", 200, 7
			)
		);

		int duplicate_credits_before = duplicate_facility.getCredits();

		// Attempt to hire another employee using the same ID.
		bool duplicate_hiring_success = duplicate_facility.hireStaff(
			std::make_unique<Technician>(
				503, "Morgan Hale", 150, 8
			)
		);

		test_passed = first_hiring_success
			&& !duplicate_hiring_success
			&& duplicate_facility.getCredits() == duplicate_credits_before
			&& duplicate_facility.findStaffById(503) != nullptr
			&& duplicate_facility.findStaffById(503)->getStaffName() == "Dr. Helena Voss";

		recordTestResult(
			test_passed,
			"Duplicate Staff ID",
			tests_passed,
			tests_failed
		);

		std::cout << "Credits Before Duplicate Attempt: "
			<< duplicate_credits_before << '\n';

		std::cout << "Credits After Duplicate Attempt: "
			<< duplicate_facility.getCredits() << '\n';

		// --------------------------------------------------
		// INVALID STAFF POINTER
		// Verify that the Facility rejects a null staff
		// pointer without changing its credit balance.
		// --------------------------------------------------

		std::cout << "\n--- INVALID STAFF POINTER TEST ---\n";

		Facility invalid_facility;

		int invalid_credits_before = invalid_facility.getCredits();

		bool invalid_hiring_success = invalid_facility.hireStaff(nullptr);

		test_passed = !invalid_hiring_success
			&& invalid_facility.getCredits() == invalid_credits_before;

		recordTestResult(
			test_passed,
			"Invalid Staff Pointer",
			tests_passed,
			tests_failed
		);

		std::cout << "Credits Before: "
			<< invalid_credits_before << '\n';

		std::cout << "Credits After: "
			<< invalid_facility.getCredits() << '\n';

		// --------------------------------------------------
		// SUCCESSFUL STAFF DISMISSAL
		// Verify that dismissing an employee removes them
		// from the Facility roster.
		// --------------------------------------------------

		std::cout << "\n--- SUCCESSFUL STAFF DISMISSAL TEST ---\n";

		Facility dismissal_facility;

		// Hire a staff member before attempting dismissal.
		bool dismissal_hiring_success = dismissal_facility.hireStaff(
			std::make_unique<Researcher>(
				504, "Dr. Nadia Cross", 200, 6
			)
		);

		// Dismiss the newly hired employee.
		bool dismissal_success = dismissal_facility.dismissStaff(504);

		// Verify that the employee is no longer in the roster.
		test_passed = dismissal_hiring_success
			&& dismissal_success
			&& dismissal_facility.findStaffById(504) == nullptr;

		recordTestResult(
			test_passed,
			"Successful Staff Dismissal",
			tests_passed,
			tests_failed
		);

		std::cout << "Staff Found After Dismissal: "
			<< (dismissal_facility.findStaffById(504) != nullptr) << '\n';

		// --------------------------------------------------
		// INVALID STAFF DISMISSAL
		// Verify that dismissing a nonexistent employee
		// fails without affecting existing staff.
		// --------------------------------------------------

		std::cout << "\n--- INVALID STAFF DISMISSAL TEST ---\n";

		Facility invalid_dismissal_facility;

		// Hire an employee who should remain in the roster.
		bool existing_hiring_success = invalid_dismissal_facility.hireStaff(
			std::make_unique<Technician>(
				505, "Morgan Hale", 150, 8
			)
		);

		// Attempt to dismiss an ID that does not exist.
		bool invalid_dismissal_success =
			invalid_dismissal_facility.dismissStaff(999);

		// Verify that the dismissal failed and the existing
		// employee remains in the roster.
		test_passed = existing_hiring_success
			&& !invalid_dismissal_success
			&& invalid_dismissal_facility.findStaffById(505) != nullptr;

		recordTestResult(
			test_passed,
			"Invalid Staff Dismissal",
			tests_passed,
			tests_failed
		);

		std::cout << "Existing Staff Still Found: "
			<< (invalid_dismissal_facility.findStaffById(505) != nullptr) << '\n';

		// --------------------------------------------------
		// STAFF COUNT
		// Verify that the Facility accurately tracks the
		// number of employees in its roster.
		// --------------------------------------------------

		std::cout << "\n--- STAFF COUNT TEST ---\n";

		Facility count_facility;

		// Verify that a new Facility starts with zero employees.
		bool empty_roster_correct = count_facility.getStaffCount() == 0;

		// Hire two employees.
		bool first_hire = count_facility.hireStaff(
			std::make_unique<Researcher>(
				506, "Dr. Evelyn Shaw", 200, 7
			)
		);

		bool second_hire = count_facility.hireStaff(
			std::make_unique<Technician>(
				507, "Morgan Hale", 150, 8
			)
		);

		// Verify that the roster count increases after hiring.
		bool hiring_count_correct = count_facility.getStaffCount() == 2;

		// Dismiss one employee.
		bool count_dismissal_success = count_facility.dismissStaff(506);

		// Verify that the roster count decreases after dismissal.
		bool dismissal_count_correct = count_facility.getStaffCount() == 1;

		test_passed = empty_roster_correct
			&& first_hire
			&& second_hire
			&& hiring_count_correct
			&& count_dismissal_success
			&& dismissal_count_correct;

		recordTestResult(
			test_passed,
			"Staff Count",
			tests_passed,
			tests_failed
		);

		std::cout << "Staff Count After Hiring: 2\n";
		std::cout << "Staff Count After Dismissal: "
			<< count_facility.getStaffCount() << '\n';

		// --------------------------------------------------
		// SUCCESSFUL STAFF ASSIGNMENT
		// Verify that assigning an employee to an upgrade
		// makes them unavailable for normal duties.
		// --------------------------------------------------

		std::cout << "\n--- STAFF ASSIGNMENT TEST ---\n";

		Facility assignment_facility;

		// Hire an employee.
		bool assignment_hiring_success = assignment_facility.hireStaff(
			std::make_unique<Researcher>(
				508, "Dr. Samuel Cross", 200, 7
			)
		);

		// Verify the employee is initially available.
		bool initially_available =
			assignment_facility.isStaffAvailable(508);

		// Assign the employee to an upgrade.
		bool assignment_success =
			assignment_facility.assignStaffToUpgrade(508);

		// Verify the employee is no longer available.
		bool unavailable_after_assignment =
			!assignment_facility.isStaffAvailable(508);

		test_passed = assignment_hiring_success
			&& initially_available
			&& assignment_success
			&& unavailable_after_assignment;

		recordTestResult(
			test_passed,
			"Successful Staff Assignment",
			tests_passed,
			tests_failed
		);

		std::cout << "Available Before Assignment: "
			<< initially_available << '\n';

		std::cout << "Available After Assignment: "
			<< assignment_facility.isStaffAvailable(508) << '\n';

		// --------------------------------------------------
		// DUPLICATE STAFF ASSIGNMENT
		// Verify that an employee cannot be assigned to
		// an upgrade more than once.
		// --------------------------------------------------

		std::cout << "\n--- DUPLICATE STAFF ASSIGNMENT TEST ---\n";

		Facility duplicate_assignment_facility;

		// Hire an employee.
		bool duplicate_assignment_hiring = duplicate_assignment_facility.hireStaff(
			std::make_unique<Technician>(
				509, "Morgan Hale", 150, 8
			)
		);

		// Perform the initial assignment.
		bool first_assignment =
			duplicate_assignment_facility.assignStaffToUpgrade(509);

		// Attempt to assign the same employee again.
		bool second_assignment =
			duplicate_assignment_facility.assignStaffToUpgrade(509);

		test_passed = duplicate_assignment_hiring
			&& first_assignment
			&& !second_assignment
			&& !duplicate_assignment_facility.isStaffAvailable(509);

		recordTestResult(
			test_passed,
			"Duplicate Staff Assignment",
			tests_passed,
			tests_failed
		);

		std::cout << "First Assignment: " << first_assignment << '\n';
		std::cout << "Second Assignment: " << second_assignment << '\n';

		// --------------------------------------------------
		// SUCCESSFUL STAFF UNASSIGNMENT
		// Verify that removing an employee's upgrade
		// assignment restores their availability.
		// --------------------------------------------------

		std::cout << "\n--- STAFF UNASSIGNMENT TEST ---\n";

		Facility unassignment_facility;

		// Hire an employee.
		bool unassignment_hiring = unassignment_facility.hireStaff(
			std::make_unique<Researcher>(
				510, "Dr. Elias Reed", 200, 6
			)
		);

		// Assign the employee to an upgrade.
		bool initial_assignment =
			unassignment_facility.assignStaffToUpgrade(510);

		// Verify the employee is unavailable.
		bool unavailable_before_unassignment =
			!unassignment_facility.isStaffAvailable(510);

		// Remove the employee's upgrade assignment.
		bool unassignment_success =
			unassignment_facility.unassignStaffFromUpgrade(510);

		// Verify the employee is available again.
		bool available_after_unassignment =
			unassignment_facility.isStaffAvailable(510);

		test_passed = unassignment_hiring
			&& initial_assignment
			&& unavailable_before_unassignment
			&& unassignment_success
			&& available_after_unassignment;

		recordTestResult(
			test_passed,
			"Successful Staff Unassignment",
			tests_passed,
			tests_failed
		);

		std::cout << "Available Before Unassignment: "
			<< !unavailable_before_unassignment << '\n';

		std::cout << "Available After Unassignment: "
			<< available_after_unassignment << '\n';

		// --------------------------------------------------
		// INVALID STAFF UNASSIGNMENT
		// Verify that an employee without an active
		// upgrade assignment cannot be unassigned.
		// --------------------------------------------------

		std::cout << "\n--- INVALID STAFF UNASSIGNMENT TEST ---\n";

		Facility invalid_unassignment_facility;

		// Hire an employee without assigning them.
		bool invalid_unassignment_hiring =
			invalid_unassignment_facility.hireStaff(
				std::make_unique<Technician>(
					511, "Morgan Hale", 150, 8
				)
			);

		// Attempt to unassign an employee who was never assigned.
		bool invalid_unassignment =
			invalid_unassignment_facility.unassignStaffFromUpgrade(511);

		// Verify the employee remains available.
		bool employee_still_available =
			invalid_unassignment_facility.isStaffAvailable(511);

		test_passed = invalid_unassignment_hiring
			&& !invalid_unassignment
			&& employee_still_available;

		recordTestResult(
			test_passed,
			"Invalid Staff Unassignment",
			tests_passed,
			tests_failed
		);

		std::cout << "Unassignment Successful: "
			<< invalid_unassignment << '\n';

		std::cout << "Employee Still Available: "
			<< employee_still_available << '\n';

		// --------------------------------------------------
		// DISMISSAL WHILE ASSIGNED
		// Verify that an employee assigned to an upgrade
		// cannot be dismissed from the Facility.
		// --------------------------------------------------

		std::cout << "\n--- DISMISSAL WHILE ASSIGNED TEST ---\n";

		Facility assigned_dismissal_facility;

		// Hire an employee.
		bool assigned_dismissal_hiring =
			assigned_dismissal_facility.hireStaff(
				std::make_unique<Researcher>(
					512, "Dr. Voss", 200, 5
				)
			);

		// Assign the employee to an upgrade.
		bool assigned_dismissal_assignment =
			assigned_dismissal_facility.assignStaffToUpgrade(512);

		// Attempt to dismiss the assigned employee.
		bool assigned_dismissal_result =
			assigned_dismissal_facility.dismissStaff(512);

		// Verify the employee remains in the roster.
		bool employee_still_exists =
			assigned_dismissal_facility.findStaffById(512) != nullptr;

		test_passed = assigned_dismissal_hiring
			&& assigned_dismissal_assignment
			&& !assigned_dismissal_result
			&& employee_still_exists;

		recordTestResult(
			test_passed,
			"Dismissal While Assigned",
			tests_passed,
			tests_failed
		);

		std::cout << "Dismissal Successful: "
			<< assigned_dismissal_result << '\n';

		std::cout << "Employee Still Exists: "
			<< employee_still_exists << '\n';

		// --------------------------------------------------
		// DISMISSAL AFTER UNASSIGNMENT
		// Verify that an employee can be dismissed after
		// their upgrade assignment has been removed.
		// --------------------------------------------------

		std::cout << "\n--- DISMISSAL AFTER UNASSIGNMENT TEST ---\n";

		Facility released_dismissal_facility;

		// Hire an employee.
		bool released_hiring =
			released_dismissal_facility.hireStaff(
				std::make_unique<Technician>(
					513, "Morgan Hale", 150, 8
				)
			);

		// Assign the employee to an upgrade.
		bool released_assignment =
			released_dismissal_facility.assignStaffToUpgrade(513);

		// Remove the employee's upgrade assignment.
		bool released_unassignment =
			released_dismissal_facility.unassignStaffFromUpgrade(513);

		// Attempt to dismiss the now-available employee.
		bool released_dismissal =
			released_dismissal_facility.dismissStaff(513);

		// Verify the employee no longer exists.
		bool employee_removed =
			released_dismissal_facility.findStaffById(513) == nullptr;

		test_passed = released_hiring
			&& released_assignment
			&& released_unassignment
			&& released_dismissal
			&& employee_removed;

		recordTestResult(
			test_passed,
			"Dismissal After Unassignment",
			tests_passed,
			tests_failed
		);

		std::cout << "Unassignment Successful: "
			<< released_unassignment << '\n';

		std::cout << "Dismissal Successful: "
			<< released_dismissal << '\n';

		std::cout << "Employee Removed: "
			<< employee_removed << '\n';

		// --------------------------------------------------
		// STAFF CONDITION DISPLAY
		// Verify that staff information and condition
		// are displayed correctly.
		// --------------------------------------------------

		std::cout << "\n--- STAFF CONDITION DISPLAY TEST ---\n";

		Facility display_facility;

		display_facility.hireStaff(
			std::make_unique<Researcher>(
				514, "Dr. Elias Reed", 200, 6
			)
		);

		// Assign the employee to an upgrade.
		display_facility.assignStaffToUpgrade(514);

		std::cout << "\n--- ASSIGNED STAFF DISPLAY ---\n";
		display_facility.displayStaffRoster();

		// Release the employee from the upgrade.
		display_facility.unassignStaffFromUpgrade(514);

		std::cout << "\n--- AVAILABLE STAFF DISPLAY ---\n";
		display_facility.displayStaffRoster();

		// Display the employee at full condition.
		std::cout << "\n--- FULL CONDITION ---\n";
		display_facility.displayStaffRoster();

		// Reduce condition to 75%.
		display_facility.findStaffById(514)->adjustStaffCondition(-25);

		std::cout << "\n--- GOOD CONDITION ---\n";
		display_facility.displayStaffRoster();

		// Reduce condition to 40%.
		display_facility.findStaffById(514)->adjustStaffCondition(-35);

		std::cout << "\n--- MODERATE CONDITION ---\n";
		display_facility.displayStaffRoster();

		// Reduce condition to 15%.
		display_facility.findStaffById(514)->adjustStaffCondition(-25);

		std::cout << "\n--- LOW CONDITION ---\n";
		display_facility.displayStaffRoster();
	}

	// ============================================================
	//                  STAFF SPECIALIZATION TESTS
	// ============================================================

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

		recordTestResult(
			test_passed,
			"Researcher Contribution",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Technician Power Restoration",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Containment Specialist Stabilization",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Containment Stability Cap",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Invalid Anomaly ID",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Security Threat Response",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Security Stability Cap",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Medical Treatment",
			tests_passed,
			tests_failed
		);

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

		recordTestResult(
			test_passed,
			"Medical Condition Cap",
			tests_passed,
			tests_failed
		);

		std::cout << "Final Condition: "
			<< technician.getStaffCondition() << '\n';
	}

	// ============================================================
	//                     TEST RESULT UTILITY
	// ============================================================

	// Records test results, updates counters, and displays the result.
	void recordTestResult(
		bool test_passed,
		const std::string& test_name,
		int& tests_passed,
		int& tests_failed)
	{
		if (test_passed)
		{
			tests_passed++;
		}
		else
		{
			tests_failed++;
		}

		std::cout << test_name << " Test: "
			<< (test_passed ? "PASS" : "FAIL") << '\n';
	}

	// ============================================================
	//                     RUN ALL TESTS IN MAIN
	// ============================================================

	// Run all automated tests and display the summary.
	void runAllTests()
	{
		int tests_passed = 0;
		int tests_failed = 0;

		// Facility system tests
		testAnomalyMaintenance(tests_passed, tests_failed);
		testResearchSystem(tests_passed, tests_failed);
		testStaffRoster(tests_passed, tests_failed);

		// Staff specialization tests
		testResearcher(tests_passed, tests_failed);
		testTechnician(tests_passed, tests_failed);
		testContainmentSpecialist(tests_passed, tests_failed);
		testSecurityOfficer(tests_passed, tests_failed);
		testMedicalOfficer(tests_passed, tests_failed);

		// Test summary
		int total_tests = tests_passed + tests_failed;

		std::cout << "\n========== TEST SUMMARY ==========\n";
		std::cout << "Tests Passed: " << tests_passed << '\n';
		std::cout << "Tests Failed: " << tests_failed << '\n';
		std::cout << "Total Tests: " << total_tests << '\n';

		std::cout << "Overall Result: "
			<< (tests_failed == 0
				? "ALL TESTS PASSED"
				: "FAILURES DETECTED")
			<< '\n';

		std::cout << "==================================\n";
	}
}