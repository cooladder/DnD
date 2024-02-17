#pragma once
#include "json.hpp"
#include <set>
#include "window.h"
#include "File.h"
class DND
{
private:
    static std::string races, classes;
    static int setup_page;
public:
    DND();
    static void race_setup();
    static void classes_setup();
    static void setup();
    static void build();
};