--update the value of key
local key=KEYS[1]
local val=redis.call("get",key);
if val==ARGV[1] then
	redis.call('set',KEYS[1],ARGV[2])
	return 1
else
	return 0
end
