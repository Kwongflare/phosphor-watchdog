#include <cstdint>
#include <iostream>
#include <sdbusplus/bus.hpp>
#include <sdbusplus/message/append.hpp>

/** An example dbus client application.
 *   *  Calls org.freedesktop.login1's ListUsers interface to find all active
 *     *  users in the system and displays their username.
 *       */

int main()
{
    using namespace sdbusplus;

    auto b = bus::new_default_system();
    auto m =
        b.new_method_call("xyz.openbmc_project.Control", "/xyz/openbmc_project/Control",
                "xyz.openbmc_project.Control.Host", "Command");
    sdbusplus::message::append("xyz.openbmc_project.Control.Host", m, 1);

    auto reply = b.call(m);

    std::cout << std::get<std::string>(reply) << "\n";

    return 0;

}

