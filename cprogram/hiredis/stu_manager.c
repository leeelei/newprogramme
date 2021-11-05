//首先将学生信息添加到数据库中，然后通过id将其结果查询出来。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<hiredis/hiredis.h>


//definiton of macro
#define SID_MAX_LENGTH 16
#define NAME_MAX_LENGTH 16
#define MAJOR_MAX_LENGTH 64
#define CMD_MAX_LENGTH 256
#define REDIS_SERVER_IP "127.0.0.1"
#define REDIS_SERVER_PORT 6379


//definition of student structure
typedef struct Stu_Info_Struct{
	char sid[SID_MAX_LENGTH];
	char name[NAME_MAX_LENGTH];
	int gender;
	char major[MAJOR_MAX_LENGTH];
}Stu_Info_Struct;
typedef enum STU_RESULT{
	SUCCESS=0,
	FAILURE=1,
}STU_RESULT;

/*declaration of function*/
STU_RESULT addStu(Stu_Info_Struct *stu); //add student information
STU_RESULT exeRedisIntCmd(char* cmd); //execute add command
STU_RESULT queryStuBySid(char* sid); //execute query command
STU_RESULT exeRedisStrCmd(char* cmd);

STU_RESULT addStu(Stu_Info_Struct *stu){ //add student information
	char cmd[CMD_MAX_LENGTH]={0};
	if(NULL == stu){
		printf("NULL pointer");
		return FAILURE;
	}

	/*assemble the redis command*/
	snprintf(cmd,CMD_MAX_LENGTH,"hset stu:%s name %s gender %d major %s",stu->sid,stu->name,stu->gender,stu->major);
	
	/*execute redis command*/
	if(FAILURE==exeRedisIntCmd(cmd)){
		printf("add student %s,%s,%d,%s,failure\n",stu->sid,stu->name,stu->gender,stu->major);
		return FAILURE;
	}
	printf("add student %s,%s,%d,%s,success",stu->sid,stu->name,stu->gender,stu->major);
	return SUCCESS;
}
STU_RESULT exeRedisIntCmd(char* cmd){
	if(NULL==cmd){
		printf("NULL pointer");
		return FAILURE;
	}

	/*connect the redis server*/
	redisContext* context=redisConnect(REDIS_SERVER_IP,REDIS_SERVER_PORT);
	if(context->err){
		redisFree(context);
		printf("%d connect redis server failure:%s\n",__LINE__,context->errstr);
		return FAILURE;
	}
	printf("connect redis server success\n");

	/*execute redis command*/
	redisReply* reply=(redisReply*)redisCommand(context,cmd);
	if(NULL==reply){
		printf("%d execute command:%s failure\n",__LINE__,cmd);
		redisFree(context);
		return FAILURE;
	}

	 //返回执行结果为整型的命令,只有状态为REDIS_REPLY_INTEGER,并且INTEGER是大于0时,才表示这种类型的命令执行成功
	 if(!(reply->type==REDIS_REPLY_INTEGER && reply->integer >0)){
		printf("%d execute command:%s failure\n",__LINE__,cmd);
		freeReplyObject(reply);
		redisFree(context);
		return FAILURE;
	 }

	freeReplyObject(reply);
	redisFree(context);
	printf("%d execute command:%s success\n",__LINE__,cmd);
	return SUCCESS;
}

STU_RESULT queryStuBySid(char* sid){
	char cmd[CMD_MAX_LENGTH]={0};
	if(NULL==sid){
		printf("NULL pointer");
		return FAILURE;
	}
	snprintf(cmd,CMD_MAX_LENGTH,"hgetall stu:%s",sid);
	if(FAILURE==exeRedisStrCmd(cmd)){
		printf("%d query stu failure\n",__LINE__);
		return FAILURE;
	}

	return SUCCESS;
}

STU_RESULT exeRedisStrCmd(char* cmd){
	if(NULL==cmd){
		printf("NULL pointer");
		return FAILURE;
	}
	/*connect the redis server*/
	redisContext* context=redisConnect(REDIS_SERVER_IP,REDIS_SERVER_PORT);
	if(context->err){
		redisFree(context);
		printf("%d connect redis server failure:%s\n",__LINE__,context->errstr);
		return FAILURE;
	}
	printf("connect redis server success\n");
	/*execute redis command*/
	redisReply* reply=(redisReply*)redisCommand(context,cmd);
	if(NULL==reply){
		printf("%d execute command:%s failure\n",__LINE__,cmd);
		redisFree(context);
		return FAILURE;
	}
	 //返回执行结果为ARRAY的命令,只有状态为REDIS_REPLY_ARRAY,并且reply->elements是大于0时,才表示这种类型的命令执行成功
	 if(!(reply->type==REDIS_REPLY_ARRAY && reply->elements >0)){
		printf("%d execute command:%s failure\n",__LINE__,cmd);
		freeReplyObject(reply);
		redisFree(context);
		return FAILURE;
	 }


	 printf("the reply->type is %d,the reply->elements are %lu\n",reply->type,reply->elements);

	 int i=0;
	 for(i=0;i<reply->elements;i++){
	 	if(i%2 == 0){
			printf("%s:",reply->element[i]->str);
		}else{
			printf("%s \n",reply->element[i]->str);
		}
	 }
	 freeReplyObject(reply);
	 redisFree(context);
	 return SUCCESS;
	
}


int main(int argc,char* argv[]){
	Stu_Info_Struct stu={
		"01",
	"hu",
	1,
	"CS"	
	};


	addStu(&stu);
	queryStuBySid("01");
	return 0;
}
