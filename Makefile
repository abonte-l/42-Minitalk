
SERVER			=	server
SERVER_SRC		=	./sources/server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)

CLIENT			=	client
CLIENT_SRC		=	./sources/client.c 
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

UTILS_SRC		=	./sources/utils.c 
UTILS_OBJ		=	$(UTILS_SRC:.c=.o)

CC				=	gcc
RM 				=	rm -f
FLAGS			= 	-Wall -Werror -Wextra	\
				-fsanitize=address	\
				-fsanitize=leak		\
				-fsanitize=undefined	\
				-g3 #			\
				-fno-omit-frame-pointer 


all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(UTILS_OBJ)
	@echo "\\033[37;1mPreparing for $(SERVER)...\033[0;1m"
	@$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)
	@echo "\033[37;1m$(SERVER) \033[32;1m[created!]\033[0;1m"

$(CLIENT) : $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "\\033[37;1mPreparing for $(CLIENT)...\033[0;1m"
	@$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)
	@echo "\033[37;1m$(CLIENT) \033[32;1m[created!]\033[0;1m"
clean :
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ) $(SERVER_OBJ_BNS) $(CLIENT_OBJ_BNS) $(UTILS_OBJ_BNS)
	@echo "\033[37;1mobjects files\033[33;1m [supp OK]\033[0;1m"

fclean : clean
	@$(RM) $(SERVER) $(CLIENT) $(SERVER_BNS) $(CLIENT_BNS)
	@echo "\033[37;1m$(SERVER) & $(CLIENT)\033[33;1m [supp OK]\033[0;1m"

re : fclean all

.PHONY: all clean fclean re
