#include "common/RhoPort.h"
#include "ext/rho/rhoruby.h"
#include "common/RhodesApp.h"
#include "logging/RhoLog.h"

extern "C" {

int rho_bluetooth_is_bluetooth_available()
{
    return 0;
}

void rho_bluetooth_off_bluetooth()
{
}

void rho_bluetooth_set_device_name(const char* device_name)
{
}

const char* rho_bluetooth_get_device_name()
{
    return "ERROR";
}

const char* rho_bluetooth_get_last_error()
{
    return "ERROR";
}

const char* rho_bluetooth_create_session(const char* role, const char* callback_url)
{
    return "ERROR";
}

void rho_bluetooth_session_set_callback(const char* connected_device_name, const char* callback_url)
{
}

void rho_bluetooth_session_disconnect(const char* connected_device_name)
{
}

int rho_bluetooth_session_get_status(const char* connected_device_name)
{
    return -1; 
}

const char* rho_bluetooth_session_read_string(const char* connected_device_name)
{
    return "ERROR";
}

void rho_bluetooth_session_write_string(const char* connected_device_name, const char* str)
{
}

VALUE rho_bluetooth_session_read_data(const char* connected_device_name)
{
    return rho_ruby_get_NIL();
}

void rho_bluetooth_session_write_data(const char* connected_device_name, VALUE data)
{
    //TODO: rho_bluetooth_session_write_data
}

const char* rho_bluetooth_create_custom_server_session(const char* client_name, const char* callback_url, int accept_any_device)
{
    return NULL;
}

const char* rho_bluetooth_create_custom_client_session(const char* server_name, const char* callback_url)
{
    return NULL;
}

const char* rho_bluetooth_stop_current_connection_process()
{
    return NULL;
}

} //extern "C"
