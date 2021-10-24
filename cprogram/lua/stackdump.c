#include<stdio.h>
#include<lua.h>
#include<lauxlib.h>
static void stackDump(lua_State* L){
	int i;
	int top=lua_gettop(L);
	for(i=top;i>0;i--){
		int t=lua_type(L,i);
		switch(t){
			case LUA_TSTRING:
				printf("'%s' ",lua_tostring(L,i));
				break;
			case LUA_TBOOLEAN:
				printf(lua_toboolean(L,i)? "true":"false");
				break;
			case LUA_TNUMBER:
				printf(" %g ",lua_tonumber(L,i));
				break;
			default:
				printf(" %s ",lua_typename(L,t));
				break;
		}

	}
	printf("  ");
	printf("\n");
}

int main(void){
	lua_State* L=luaL_newstate();
	lua_pushboolean(L,1);
	lua_pushnumber(L,10);
	lua_pushnil(L);
	lua_pushstring(L,"Hello");
	printf("the length is %d\n",lua_gettop(L));
	stackDump(L);

	return 0;
}
