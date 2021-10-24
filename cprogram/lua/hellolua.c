#include<stdio.h>
#include<lua.h>
#include<lualib.h>
#include<lauxlib.h>
//the lua interpreter
lua_State* L;
int luaadd(int x ,int y){
	int sum;
	//the function name
	lua_getglobal(L,"add");
	//the first argument
	lua_pushnumber(L,x);
	//the second argument
	lua_pushnumber(L,y);
	
	//call the function with 2 arguments, return 1 result.
	lua_call(L,2,1);

	//get the result.
	sum=(int)lua_tonumber(L,-1);

	//clean up the return
	lua_pop(L,1);
	return sum;
}

int main(int argc,char* argv[]){
	int sum;
	//initialize Lua
//	L=lua_open();  lua_open is deprecated already.
	L=luaL_newstate();
	//local lua base libraries
	luaL_openlibs(L);
	//local the script
	luaL_dofile(L,"add.lua");

	//call the add function
	sum=luaadd(10,15);

	//print the result
	printf("the sum of is %d \n",sum);
	//clean up lua
	lua_close(L);
	return 0;

}
