#ifndef SALAMAPPER_H
#define SALAMAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct TreeHandle TreeHandle;

TreeHandle* CreateTree(const char* format_string, const char* root_id);
void ClearTree(TreeHandle* handle);
char* GetTree(TreeHandle *handle);
void FreeString(char* str);

#ifdef __cplusplus
}
#endif

#endif