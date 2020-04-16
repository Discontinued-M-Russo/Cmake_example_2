#include <exception>
#include <iostream>
#include <fstream>
#include <string>

#include "src/rectangle.h"

#include <boost/log/trivial.hpp>
#include <boost/log/common.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/utility/setup/from_stream.hpp>

namespace logging = boost::log;
namespace attrs = boost::log::attributes;

using namespace std;


int main() {

    // Open the file
    std::string logFileSettingsName = "../log/settings.txt";
    std::ifstream settings(logFileSettingsName);
    if (!settings.is_open())
    {
        std::cout << "Could not open log settings file: " << logFileSettingsName << std::endl;
        return 0;
    }

    // Read the settings and initialize logging library
    logging::init_from_stream(settings);

    // Add some attributes
    logging::core::get()->add_global_attribute("TimeStamp", attrs::local_clock()); // each log line gets a timestamp
    logging::core::get()->add_global_attribute("LineID", attrs::counter<unsigned int>(1)); // lines are sequentially numbered

    cout << "Hello, World!" << endl;

    rectangle rect;
    rect.set_values (3,4);
    BOOST_LOG_TRIVIAL(info) << "First area: " << rect.area();

    rectangle rect2(2,5);
    BOOST_LOG_TRIVIAL(info) << "Second area: " << rect2.area();

    BOOST_LOG_TRIVIAL(trace) << "This is a trace severity record";
    BOOST_LOG_TRIVIAL(debug) << "This is a debug severity record";
    BOOST_LOG_TRIVIAL(info) << "This is an info severity record";
    BOOST_LOG_TRIVIAL(warning) << "This is a warning severity record";
    BOOST_LOG_TRIVIAL(error) << "This is an error severity record";
    BOOST_LOG_TRIVIAL(fatal) << "This is a fatal severity record";

    return 0;
}