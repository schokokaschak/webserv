.SILENT:

NAME = webserv

SRCS = src/main.cpp src/Logger.cpp

HEADERS	= include/Webserv.hpp 

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all:
	@$(MAKE) $(NAME) -j5

$(NAME) : $(OBJS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@for i in / - \\ \|; do \
        echo "$$i"; \
        sleep 0.3; \
        tput cuu1; \
        tput el; \
    done
	@echo "webserv ready"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re