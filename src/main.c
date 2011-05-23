/* main.c generated by valac 0.10.4, the Vala compiler
 * generated from main.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <stdio.h>
#include <ibus.h>
#include <gtk/gtk.h>
#include <unistd.h>
#include <gobject/gvaluecollector.h>


#define ICP_TYPE_MAIN (icp_main_get_type ())
#define ICP_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ICP_TYPE_MAIN, icpMain))
#define ICP_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ICP_TYPE_MAIN, icpMainClass))
#define ICP_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ICP_TYPE_MAIN))
#define ICP_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ICP_TYPE_MAIN))
#define ICP_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ICP_TYPE_MAIN, icpMainClass))

typedef struct _icpMain icpMain;
typedef struct _icpMainClass icpMainClass;
typedef struct _icpMainPrivate icpMainPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
typedef struct _icpParamSpecMain icpParamSpecMain;

struct _icpMain {
	GTypeInstance parent_instance;
	volatile int ref_count;
	icpMainPrivate * priv;
};

struct _icpMainClass {
	GTypeClass parent_class;
	void (*finalize) (icpMain *self);
};

struct _icpParamSpecMain {
	GParamSpec parent_instance;
};


extern GMainLoop* icp_main_loop;
GMainLoop* icp_main_loop = NULL;
extern gboolean icp_config_commandline_options_show_version;
extern gboolean icp_config_commandline_options_show_xml;
extern gboolean icp_config_commandline_options_replace_running_process;
extern gboolean icp_config_commandline_options_do_not_connect_ibus;
static gpointer icp_main_parent_class = NULL;

gpointer icp_main_ref (gpointer instance);
void icp_main_unref (gpointer instance);
GParamSpec* icp_param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void icp_value_set_main (GValue* value, gpointer v_object);
void icp_value_take_main (GValue* value, gpointer v_object);
gpointer icp_value_get_main (const GValue* value);
GType icp_main_get_type (void) G_GNUC_CONST;
enum  {
	ICP_MAIN_DUMMY_PROPERTY
};
gint icp_main_main (char** args, int args_length1);
void icp_config_init (char*** args, int* args_length1);
#define ICP_CONFIG_version "0.8.0.20101124"
void icp_ibus_binding_init (void);
char* icp_ibus_binding_get_component_xml (void);
void icp_pinyin_init (void);
void icp_frontend_init (void);
void icp_database_init (void);
void icp_dbus_binding_init (void);
void icp_lua_binding_init (void);
void icp_ibus_binding_register (void);
icpMain* icp_main_new (void);
icpMain* icp_main_construct (GType object_type);
static void icp_main_finalize (icpMain* obj);



gint icp_main_main (char** args, int args_length1) {
	gint result = 0;
	GMainLoop* _tmp3_;
	gdk_threads_init ();
	dbus_g_thread_init ();
	icp_config_init (&args, &args_length1);
	if (icp_config_commandline_options_show_version) {
		fprintf (stdout, "ibus-cloud-pinyin %s [built with ibus %d.%d.%d]\n" "Copyright (c) 2010 WU Jun <quark@lihdd.net>\n", ICP_CONFIG_version, IBUS_MAJOR_VERSION, IBUS_MINOR_VERSION, IBUS_MICRO_VERSION);
		result = 0;
		return result;
	}
	if (icp_config_commandline_options_show_xml) {
		char* _tmp0_;
		icp_ibus_binding_init ();
		fprintf (stdout, "%s", _tmp0_ = icp_ibus_binding_get_component_xml ());
		_g_free0 (_tmp0_);
		result = 0;
		return result;
	}
	gdk_init (&args_length1, &args);
	gtk_init (&args_length1, &args);
	if (icp_config_commandline_options_replace_running_process) {
		char* _tmp1_;
		char* _tmp2_;
		system (_tmp2_ = g_strconcat ("for i in `ps -C ibus-engine-cloud-pinyin -o pid=`; do ", _tmp1_ = g_strdup_printf ("[ \"$i\" = %d ] || kill $i; done", (gint) getpid ()), NULL));
		_g_free0 (_tmp2_);
		_g_free0 (_tmp1_);
	}
	icp_pinyin_init ();
	icp_frontend_init ();
	icp_database_init ();
	icp_dbus_binding_init ();
	icp_ibus_binding_init ();
	icp_lua_binding_init ();
	if (!icp_config_commandline_options_do_not_connect_ibus) {
		g_usleep ((gulong) 100000);
		icp_ibus_binding_register ();
	}
	icp_main_loop = (_tmp3_ = g_main_loop_new (NULL, FALSE), _g_main_loop_unref0 (icp_main_loop), _tmp3_);
	g_main_loop_run (icp_main_loop);
	result = 0;
	return result;
}


int main (int argc, char ** argv) {
	g_thread_init (NULL);
	g_type_init ();
	return icp_main_main (argv, argc);
}


icpMain* icp_main_construct (GType object_type) {
	icpMain* self = (icpMain*) g_type_create_instance (object_type);
	return self;
}


icpMain* icp_main_new (void) {
	return icp_main_construct (ICP_TYPE_MAIN);
}


static void icp_value_main_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void icp_value_main_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		icp_main_unref (value->data[0].v_pointer);
	}
}


static void icp_value_main_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = icp_main_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer icp_value_main_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* icp_value_main_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		icpMain* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = icp_main_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* icp_value_main_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	icpMain** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = icp_main_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* icp_param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	icpParamSpecMain* spec;
	g_return_val_if_fail (g_type_is_a (object_type, ICP_TYPE_MAIN), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer icp_value_get_main (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, ICP_TYPE_MAIN), NULL);
	return value->data[0].v_pointer;
}


void icp_value_set_main (GValue* value, gpointer v_object) {
	icpMain* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, ICP_TYPE_MAIN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, ICP_TYPE_MAIN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		icp_main_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		icp_main_unref (old);
	}
}


void icp_value_take_main (GValue* value, gpointer v_object) {
	icpMain* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, ICP_TYPE_MAIN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, ICP_TYPE_MAIN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		icp_main_unref (old);
	}
}


static void icp_main_class_init (icpMainClass * klass) {
	icp_main_parent_class = g_type_class_peek_parent (klass);
	ICP_MAIN_CLASS (klass)->finalize = icp_main_finalize;
}


static void icp_main_instance_init (icpMain * self) {
	self->ref_count = 1;
}


static void icp_main_finalize (icpMain* obj) {
	icpMain * self;
	self = ICP_MAIN (obj);
}


GType icp_main_get_type (void) {
	static volatile gsize icp_main_type_id__volatile = 0;
	if (g_once_init_enter (&icp_main_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { icp_value_main_init, icp_value_main_free_value, icp_value_main_copy_value, icp_value_main_peek_pointer, "p", icp_value_main_collect_value, "p", icp_value_main_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (icpMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) icp_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (icpMain), 0, (GInstanceInitFunc) icp_main_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType icp_main_type_id;
		icp_main_type_id = g_type_register_fundamental (g_type_fundamental_next (), "icpMain", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&icp_main_type_id__volatile, icp_main_type_id);
	}
	return icp_main_type_id__volatile;
}


gpointer icp_main_ref (gpointer instance) {
	icpMain* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void icp_main_unref (gpointer instance) {
	icpMain* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		ICP_MAIN_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




