/* request-main.c generated by valac 0.10.4, the Vala compiler
 * generated from request-main.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <lua.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <stdio.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _lua_close0(var) ((var == NULL) ? NULL : (var = (lua_close (var), NULL)))


extern char* script;
char* script = NULL;
extern char* pinyins;
char* pinyins = NULL;
extern gint priority;
gint priority = 0;
extern double timeout;
double timeout = 0.0;
extern gboolean responsed;
gboolean responsed = FALSE;

gint l_response (lua_State* vm);
static gboolean _dynamic_cloud_set_response0 (DBusGProxy* self, const char* param1, const char* param2, gint param3, GError** error);
void* timeout_thread (void);
gint _vala_main (char** args, int args_length1);
static gint _l_response_lua_cfunction (lua_State* vm);
static void* _timeout_thread_gthread_func (gpointer self);



static gboolean _dynamic_cloud_set_response0 (DBusGProxy* self, const char* param1, const char* param2, gint param3, GError** error) {
	gboolean result;
	dbus_g_proxy_call (self, "CloudSetResponse", error, G_TYPE_STRING, param1, G_TYPE_STRING, param2, G_TYPE_INT, param3, G_TYPE_INVALID, G_TYPE_BOOLEAN, &result, G_TYPE_INVALID);
	if (*error) {
		return FALSE;
	}
	return result;
}


gint l_response (lua_State* vm) {
	gint result = 0;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (vm != NULL, 0);
	if (lua_isstring (vm, 1)) {
		char* content;
		DBusGConnection* conn;
		DBusGProxy* test_server_object;
		gboolean ret;
		responsed = TRUE;
		content = g_strdup (lua_tostring (vm, 1));
		conn = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_free0 (content);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
		test_server_object = dbus_g_proxy_new_for_name (conn, "org.ibus.CloudPinyin", "/org/ibus/CloudPinyin", "org.ibus.CloudPinyin");
		ret = _dynamic_cloud_set_response0 (test_server_object, pinyins, content, priority, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (test_server_object);
			_dbus_g_connection_unref0 (conn);
			_g_free0 (content);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
		_g_object_unref0 (test_server_object);
		_dbus_g_connection_unref0 (conn);
		_g_free0 (content);
	}
	result = 0;
	return result;
}


void* timeout_thread (void) {
	void* result = NULL;
	g_usleep (((gulong) timeout) * 1000000);
	exit (1);
	result = NULL;
	return result;
}


static gint _l_response_lua_cfunction (lua_State* vm) {
	gint result;
	result = l_response (vm);
	return result;
}


static void* _timeout_thread_gthread_func (gpointer self) {
	void* result;
	result = timeout_thread ();
	return result;
}


gint _vala_main (char** args, int args_length1) {
	gint result = 0;
	GOptionEntry _tmp0_ = {0};
	GOptionEntry entrie_script;
	GOptionEntry _tmp1_ = {0};
	GOptionEntry entrie_request_pinyins;
	GOptionEntry _tmp2_ = {0};
	GOptionEntry entrie_request_priority;
	GOptionEntry _tmp3_ = {0};
	GOptionEntry entrie_request_timeout;
	GOptionEntry _tmp4_ = {0};
	GOptionEntry entrie_null;
	GOptionContext* context;
	GOptionEntry* _tmp5_ = NULL;
	GOptionEntry* _tmp6_;
	gint _tmp6__length1;
	lua_State* vm;
	char* _tmp7_;
	char* _tmp8_;
	gint _tmp9_ = 0;
	GError * _inner_error_ = NULL;
	priority = 1;
	timeout = 3.0;
	responsed = FALSE;
	entrie_script = (_tmp0_.long_name = "script", _tmp0_.short_name = 'c', _tmp0_.flags = (gint) G_OPTION_FLAG_HIDDEN, _tmp0_.arg = G_OPTION_ARG_FILENAME, _tmp0_.arg_data = &script, _tmp0_.description = "", _tmp0_.arg_description = NULL, _tmp0_);
	entrie_request_pinyins = (_tmp1_.long_name = "request-pinyins", _tmp1_.short_name = 'r', _tmp1_.flags = (gint) G_OPTION_FLAG_HIDDEN, _tmp1_.arg = G_OPTION_ARG_STRING, _tmp1_.arg_data = &pinyins, _tmp1_.description = "", _tmp1_.arg_description = NULL, _tmp1_);
	entrie_request_priority = (_tmp2_.long_name = "request-priority", _tmp2_.short_name = 'p', _tmp2_.flags = (gint) G_OPTION_FLAG_HIDDEN, _tmp2_.arg = G_OPTION_ARG_INT, _tmp2_.arg_data = &priority, _tmp2_.description = "", _tmp2_.arg_description = NULL, _tmp2_);
	entrie_request_timeout = (_tmp3_.long_name = "request-timeout", _tmp3_.short_name = 't', _tmp3_.flags = (gint) G_OPTION_FLAG_HIDDEN, _tmp3_.arg = G_OPTION_ARG_DOUBLE, _tmp3_.arg_data = &timeout, _tmp3_.description = "", _tmp3_.arg_description = NULL, _tmp3_);
	entrie_null = (_tmp4_.long_name = NULL, _tmp4_);
	context = g_option_context_new ("- internal used by ibus-cloud-pinyin");
	g_option_context_add_main_entries (context, (_tmp6_ = (_tmp5_ = g_new0 (GOptionEntry, 5), _tmp5_[0] = entrie_request_pinyins, _tmp5_[1] = entrie_request_timeout, _tmp5_[2] = entrie_request_priority, _tmp5_[3] = entrie_script, _tmp5_[4] = entrie_null, _tmp5_), _tmp6__length1 = 5, _tmp6_), NULL);
	_tmp6_ = (g_free (_tmp6_), NULL);
	{
		g_option_context_parse (context, &args_length1, &args, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_OPTION_ERROR) {
				goto __catch0_g_option_error;
			}
			_g_option_context_free0 (context);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
	}
	goto __finally0;
	__catch0_g_option_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			;
			_g_error_free0 (e);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (context);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	if (script == NULL) {
		result = 4;
		_g_option_context_free0 (context);
		return result;
	}
	vm = (lua_State*) luaL_newstate ();
	luaL_openlibs (vm);
	lua_checkstack (vm, 1);
	lua_pushstring (vm, _tmp7_ = g_strdup_printf ("%s/ibus/cloud-pinyin", g_get_user_cache_dir ()));
	_g_free0 (_tmp7_);
	lua_setglobal (vm, "user_cache_path");
	lua_checkstack (vm, 1);
	lua_pushstring (vm, pinyins);
	lua_setglobal (vm, "pinyin");
	lua_register (vm, "response", _l_response_lua_cfunction);
	luaL_loadstring (vm, _tmp8_ = g_strdup_printf ("dofile([[%s]])", script));
	_g_free0 (_tmp8_);
	g_thread_create (_timeout_thread_gthread_func, NULL, FALSE, &_inner_error_);
	if (_inner_error_ != NULL) {
		_lua_close0 (vm);
		_g_option_context_free0 (context);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	if (lua_pcall (vm, 0, 0, 0) != 0) {
		char* error_message;
		error_message = g_strdup (lua_tostring (vm, -1));
		fprintf (stderr, "REQUEST FATAL: %s\n", error_message);
		_g_free0 (error_message);
	}
	if (responsed) {
		_tmp9_ = 0;
	} else {
		_tmp9_ = 2;
	}
	result = _tmp9_;
	_lua_close0 (vm);
	_g_option_context_free0 (context);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}




