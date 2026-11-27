
#include "FacilityProject.h"

// ============================================================
// FacilityProject.cpp
// Purpose: Implements shared facility project functionality,
//          including project initialization, daily progression,
//          completion tracking, and information retrieval.
// ============================================================

// ===================== Constructor ==========================

// Initialize a facility project.
FacilityProject::FacilityProject(std::string name, int duration)
    : projectName(name),
    daysRemaining(duration),
    isCompleted(false)
{
}

// ================= Project Lifecycle ========================

// Advance the project by one in-game day.
void FacilityProject::advanceProject()
{
    if (isCompleted)
    {
        return;
    }

    if (daysRemaining > 0)
    {
        daysRemaining--;
    }

    if (daysRemaining <= 0)
    {
        isCompleted = true;
    }
}

// ======================= Getters ============================

// Return the project name.
std::string FacilityProject::getProjectName() const
{
    return projectName;
}

// Return the number of days remaining.
int FacilityProject::getDaysRemaining() const
{
    return daysRemaining;
}

// Return whether the project has been completed.
bool FacilityProject::getIsCompleted() const
{
    return isCompleted;
}
