#include <Windows.h>
#include <shlobj.h>

#include <cinttypes>

#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <locale>
#include <string>
#include <thread>
#include <unordered_map>

#include <MinHook.h>

#include "il2cpp_symbols.hpp"


extern bool g_dump_entries;
extern bool g_enable_logger;
extern bool g_enable_console;
extern int g_max_fps;
extern bool g_unlock_size;
extern float g_ui_scale;
extern float g_aspect_ratio;
extern bool g_replace_font;
extern bool g_auto_fullscreen;

il2cpp_string_new_utf16_t il2cpp_string_new_utf16;
il2cpp_string_new_t il2cpp_string_new;
il2cpp_domain_get_t il2cpp_domain_get;
il2cpp_domain_assembly_open_t il2cpp_domain_assembly_open;
il2cpp_assembly_get_image_t il2cpp_assembly_get_image;
il2cpp_class_from_name_t il2cpp_class_from_name;
il2cpp_class_get_methods_t il2cpp_class_get_methods;
il2cpp_class_get_method_from_name_t il2cpp_class_get_method_from_name;
il2cpp_method_get_param_t il2cpp_method_get_param;
il2cpp_object_new_t il2cpp_object_new;
il2cpp_resolve_icall_t il2cpp_resolve_icall;
il2cpp_array_new_t il2cpp_array_new;
il2cpp_thread_attach_t il2cpp_thread_attach;
il2cpp_thread_detach_t il2cpp_thread_detach;
il2cpp_image_get_class_count_t il2cpp_image_get_class_count;
il2cpp_image_get_class_t il2cpp_image_get_class;
il2cpp_class_get_name_t il2cpp_class_get_name;
il2cpp_class_get_field_from_name_t il2cpp_class_get_field_from_name;
il2cpp_field_get_offset_t il2cpp_field_get_offset;

il2cpp_array_length_t il2cpp_array_length;

char* il2cpp_array_addr_with_size(void* array, int32_t size, uintptr_t idx)
{
	return ((char*)array) + kIl2CppSizeOfArray + size * idx;
}

namespace il2cpp_symbols
{
#define RESOLVE_IMPORT(name) name = reinterpret_cast<name##_t>(GetProcAddress(game_module, #name))

	void* il2cpp_domain = nullptr;

	void init(HMODULE game_module)
	{
		RESOLVE_IMPORT(il2cpp_string_new_utf16);
		RESOLVE_IMPORT(il2cpp_string_new);
		RESOLVE_IMPORT(il2cpp_domain_get);
		RESOLVE_IMPORT(il2cpp_domain_assembly_open);
		RESOLVE_IMPORT(il2cpp_assembly_get_image);
		RESOLVE_IMPORT(il2cpp_class_from_name);
		RESOLVE_IMPORT(il2cpp_class_get_methods);
		RESOLVE_IMPORT(il2cpp_class_get_method_from_name);
		RESOLVE_IMPORT(il2cpp_method_get_param);
		RESOLVE_IMPORT(il2cpp_object_new);
		RESOLVE_IMPORT(il2cpp_resolve_icall);
		RESOLVE_IMPORT(il2cpp_array_new);
		RESOLVE_IMPORT(il2cpp_thread_attach);
		RESOLVE_IMPORT(il2cpp_thread_detach);
		RESOLVE_IMPORT(il2cpp_image_get_class_count);
		RESOLVE_IMPORT(il2cpp_image_get_class);
		RESOLVE_IMPORT(il2cpp_class_get_name);
		RESOLVE_IMPORT(il2cpp_class_get_field_from_name);
		RESOLVE_IMPORT(il2cpp_field_get_offset);
		RESOLVE_IMPORT(il2cpp_array_length);

		il2cpp_domain = il2cpp_domain_get();
	}

	void* get_string(const char* str) {
		return il2cpp_string_new(str);
	}

	uint32_t get_array_length(void* array) {
		return il2cpp_array_length(array);
	}

	void class_get_method(void* klass)
	{

		void* iter = nullptr;
		while (const MethodInfo* method = il2cpp_class_get_methods(klass, &iter))
		{
			printf("method name is %s \n", method->name);
			printf("method address is %p \n", method->methodPointer);
			printf("method arg count is %p \n", method->parameters_count);
		}

		return;
	}

	size_t get_image_class_count(void* image)
	{
		size_t num = il2cpp_image_get_class_count(image);
		printf("length is %p \n", num);
		return num;
	}

	void* image_get_class(void* image, size_t index)
	{
		auto klass = il2cpp_image_get_class(image, index);
		printf("get class from image is %p \n", klass);
		return klass;
	}

	char* class_get_name(void* klass)
	{
		char* name = il2cpp_class_get_name(klass);
		printf("class get name is %s \n", name);
		return name;
	}

	void* get_class(const char* assemblyName, const char* namespaze, const char* klassName)
	{
		auto assembly = il2cpp_domain_assembly_open(il2cpp_domain, assemblyName);
		auto image = il2cpp_assembly_get_image(assembly);
		return il2cpp_class_from_name(image, namespaze, klassName);
	}

	void* new_object(void* klass) {
		return il2cpp_object_new(klass);
	}

	uintptr_t get_method_pointer(const char* assemblyName, const char* namespaze,
		const char* klassName, const char* name, int argsCount, int index)
	{
		auto assembly = il2cpp_domain_assembly_open(il2cpp_domain, assemblyName);
		printf("get dll success %p\n", assembly);
		auto image = il2cpp_assembly_get_image(assembly);
		printf("get image success %p\n", image);
		//auto new_klass = image_get_class(image, 3648);
		//class_get_name(new_klass);
		void* klass;
		if (index != -1) {
			klass = image_get_class(image, index);
		}
		else {
			klass = il2cpp_class_from_name(image, namespaze, klassName);
			//class_get_name(klass);
			//class_get_method(klass);
		}		
		//class_get_method(klass);
		printf("get class success %p\n", klass);

		return il2cpp_class_get_method_from_name(klass, name, argsCount)->methodPointer;
	}

	MethodInfo* get_method(const char* assemblyName, const char* namespaze,
		const char* klassName, const char* name, int argsCount)
	{
		auto assembly = il2cpp_domain_assembly_open(il2cpp_domain, assemblyName);
		auto image = il2cpp_assembly_get_image(assembly);
		auto klass = il2cpp_class_from_name(image, namespaze, klassName);

		return il2cpp_class_get_method_from_name(klass, name, argsCount);
	}

	uintptr_t find_method(const char* assemblyName, const char* namespaze,
		const char* klassName, std::function<bool(const MethodInfo*)> predict)
	{
		auto assembly = il2cpp_domain_assembly_open(il2cpp_domain, assemblyName);
		auto image = il2cpp_assembly_get_image(assembly);
		auto klass = il2cpp_class_from_name(image, namespaze, klassName);

		void* iter = nullptr;
		while (const MethodInfo* method = il2cpp_class_get_methods(klass, &iter))
		{
			if (predict(method))
				return method->methodPointer;
		}

		return 0;
	}

	uintptr_t get_method_pointer_base(const char* assemblyName, const char* namespaze,
		const char* klassName, const char* name, int argsCount, size_t offset)
	{
		auto assembly = il2cpp_domain_assembly_open(il2cpp_domain, assemblyName);
		auto image = il2cpp_assembly_get_image(assembly);
		auto klass = il2cpp_class_from_name(image, namespaze, klassName);

		auto base = (uintptr_t)((size_t)(il2cpp_class_get_method_from_name(klass, name, argsCount)->methodPointer) - offset);

		printf("method pointer base is %p \n", base);

		return base;
	}

	size_t get_field_offset(const char* assemblyName, const char* namespaze,
		const char* klassName, const char* name)
	{
		auto assembly = il2cpp_domain_assembly_open(il2cpp_domain, assemblyName);
		auto image = il2cpp_assembly_get_image(assembly);
		auto klass = il2cpp_class_from_name(image, namespaze, klassName);
		auto field = il2cpp_class_get_field_from_name(klass, name);

		return il2cpp_field_get_offset(field);
	}

}