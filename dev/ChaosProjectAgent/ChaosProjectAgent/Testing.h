#pragma once

#include <string>

namespace Testing
{
    // Run all automated tests and display the summary.
    void runAllTests();

    // Core facility system tests.
    void testAnomalyMaintenance(int& tests_passed, int& tests_failed);
    void testResearchSystem(int& tests_passed, int& tests_failed);
    void testStaffRoster(int& tests_passed, int& tests_failed);

    // Staff specialization tests.
    void testResearcher(int& tests_passed, int& tests_failed);
    void testTechnician(int& tests_passed, int& tests_failed);
    void testContainmentSpecialist(int& tests_passed, int& tests_failed);
    void testSecurityOfficer(int& tests_passed, int& tests_failed);
    void testMedicalOfficer(int& tests_passed, int& tests_failed);

    // Test result utility.
    void recordTestResult(
        bool test_passed,
        const std::string& test_name,
        int& tests_passed,
        int& tests_failed
    );
}