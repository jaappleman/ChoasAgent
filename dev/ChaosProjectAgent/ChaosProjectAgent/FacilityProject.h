

#pragma once

// ============================================================
// FacilityProject.h
// Purpose: Defines the abstract base class for facility
//          projects, providing shared project information
//          and lifecycle functionality.
// ============================================================

// ======================== Includes ==========================

#include <string>

// ===================== Class Declaration ====================

class FacilityProject
{
protected:
    // ================= Project Information ==================

    std::string projectName;
    int daysRemaining;
    bool isCompleted;

public:
    // ===================== Constructor ======================

    FacilityProject(std::string name, int duration);

    // ====================== Destructor ======================

    virtual ~FacilityProject() = default;

    // ================= Project Lifecycle ====================

    virtual void advanceProject();

    // ======================= Getters ========================

    std::string getProjectName() const;
    int getDaysRemaining() const;
    bool getIsCompleted() const;
};
