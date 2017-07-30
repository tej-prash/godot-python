#ifndef PYTHONSCRIPT_API_H
#define PYTHONSCRIPT_API_H

#include "modules/gdnative/godot/gdnative.h"
#include "modules/pluginscript/pluginscript.h"
#include "cffi_bindings/api_struct.h"

typedef void *cffi_handle;

extern void pybind_init();
extern void pybind_get_template_source_code(const godot_string *class_name, const godot_string *base_class_name, godot_string *r_src);

extern godot_pluginscript_script_manifest pybind_script_init(const godot_string *path, const godot_string *source, godot_error *r_error);
extern void pybind_script_finish(godot_pluginscript_script_handle handle);
extern void pybind_script_get_name(godot_pluginscript_script_handle handle, godot_string *r_name);
extern godot_bool pybind_script_is_tool(godot_pluginscript_script_handle handle);
extern godot_bool pybind_script_can_instance(godot_pluginscript_script_handle handle);

extern godot_pluginscript_instance_handle pybind_instance_init(godot_pluginscript_script_handle, godot_object *);
extern void pybind_instance_finish(godot_pluginscript_instance_handle);

extern godot_bool pybind_instance_set_prop(godot_pluginscript_instance_handle handle, const godot_string *p_name, const godot_variant *p_value);
extern godot_bool pybind_instance_get_prop(godot_pluginscript_instance_handle handle, const godot_string *p_name, godot_variant *r_ret);
extern void pybind_instance_notification(godot_pluginscript_instance_handle handle, int notification);
extern godot_variant pybind_instance_call_method(godot_pluginscript_instance_handle handle, const godot_string *p_method, const godot_variant **p_args, int p_argcount, godot_variant_call_error *r_error);

extern cffi_handle pybind_load_exposed_class_per_module(const wchar_t *modname);
extern cffi_handle pybind_instanciate_from_classname(const wchar_t *classname);
extern cffi_handle pybind_wrap_gdobj_with_class(cffi_handle cls_handle, void *gdobj);
extern void pybind_release_instance(cffi_handle handle);
extern void pybind_call_meth(cffi_handle handle, const wchar_t *methname, void **args, int argcount, void *ret, int *error);
extern godot_bool pybind_set_prop(cffi_handle handle, const wchar_t *propname, const godot_variant *value);
extern godot_bool pybind_get_prop(cffi_handle handle, const wchar_t *propname, godot_variant *ret);
extern godot_bool pybind_get_prop_type(cffi_handle handle, const wchar_t *propname, int *prop_type);
extern const godot_string *pybind_get_prop_list(cffi_handle handle);
extern godot_bool pybind_get_prop_default_value(cffi_handle handle, const wchar_t *propname, godot_variant *r_val);
extern godot_bool pybind_get_prop_info(cffi_handle handle, const wchar_t *propname, pybind_prop_info *r_prop_info);
extern const godot_string *pybind_get_meth_list(cffi_handle handle);
extern godot_bool pybind_get_meth_info(cffi_handle handle, const wchar_t *methname, int *r_argcount);
extern godot_bool pybind_has_meth(cffi_handle handle, const wchar_t *methname);
extern godot_bool pybind_is_tool(cffi_handle handle);
extern void pybind_notification(cffi_handle handle, int notification);
extern godot_int pybind_get_rpc_mode(cffi_handle handle, const wchar_t *methname);
extern godot_int pybind_get_rset_mode(cffi_handle handle, const wchar_t *varname);
extern const godot_string *pybind_get_signal_list(cffi_handle handle);
extern godot_bool pybind_has_signal(cffi_handle handle, const wchar_t *signalname);
extern godot_bool pybind_get_signal_info(cffi_handle handle, const wchar_t *signalname, int *r_argcount);
extern void pybind_get_class_name(cffi_handle handle, godot_string *r_name);

#endif // PYTHONSCRIPT_API_H
