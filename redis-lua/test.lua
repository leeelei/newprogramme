--return KEYS[1] ARGV[1]
--return redis.call('get','bar')
--return KEYS[1],KEYS[2],ARGV[1],ARGV[2]
if(KEYS[1]==KEYS[2]) then
	return 1

