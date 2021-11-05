#include<stdio.h>
#include<hiredis/hiredis.h>
redisContext* c;
int get_int_command(char int_command[200]){
	redisReply* reply=(redisReply*)redisCommand(c,int_command);
	printf("the result of command %s: %d\n",int_command,reply->type);

	if(reply->type == 3){
		printf("the result of %s is %lld\n",int_command,reply->integer);
		return reply->integer;
	}else if(reply->type==4)
		return -1;
	else if(reply->type==6)
		return -2;
	freeReplyObject(reply);
	return 0;
}

char* get_string_command(char string_command[200]){
	redisReply* reply=(redisReply*)redisCommand(c,string_command);
	printf("the result of command %s: %d\n",string_command,reply->type);
	if(reply->type == 1){
		printf("the result of %s is %s\n",string_command,reply->str);
		return reply->str;
	}else if(reply->type==4)
		return "not exists";
	else if(reply->type==6)
		return reply->str;
	freeReplyObject(reply);
	return "";
}

void run_command(char run_command[200]){
	redisReply* reply=(redisReply*)redisCommand(c,run_command);
	printf("reply type: %d\n",reply->type);

	printf("the result of %s is %s\n",run_command,reply->str);
//	if(reply->type ==5)
//		printf("the result of %s is %s\n",run_command,reply->str);
	freeReplyObject(reply);
}


int main(){
	c=redisConnect("127.0.0.1",6379);
	if(c->err){
		printf("connect redis failure:%s\n",c->errstr);
		return 0;
	}else
		printf("connect redis successfully!\n");
	//if need password
	//reply=(redisReply*)redisCommand(c,"auth %s",redis_password);
	//if(reply->type==REDIS_REPLY_ERRO)
	//	printf("redis auth failed\n")
	//	else
	//	printf("redis auth successfully\n");
	//freeReplyObject(reply);
	redisReply* reply=(redisReply*)redisCommand(c,"select 1");//select db
	printf("Select: 1 %s\n",reply->str);
	freeReplyObject(reply);


	run_command("set foo \"hello world\"");
	//delete command
	run_command("del foo");


	return 0;
}

