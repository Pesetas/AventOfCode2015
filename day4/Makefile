NAME		= day4.out

UTILS_DIR	= ../utils/
UTILS_FILES	= hash strlcpy itoa
SRCS 		= $(addprefix $(UTILS_DIR), $(addsuffix .c, $(UTILS_FILES)))
OBJS		= *.o

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror

HASH_LIB_F	= -lssl -lcrypto

RM			= rm -f

${NAME}:
			${CC} ${CFLAGS} -o ${NAME} day4.c ${SRCS} ${HASH_LIB_F}

all:		${NAME}

clean:		
			${RM} ${NAME}

re:			clean all

.PHONY:		all clean re