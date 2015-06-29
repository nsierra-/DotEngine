#               .-'''''-.
#             .'         `.
#            :             :   File       : Makefile
#           :               :  Creation   : 2015-05-17 02:38:33
#           :      _/|      :  Last Edit  : 2015-05-23 06:51:37
#            :   =/_/      :   Author     : nsierra-
#             `._/ |     .'    Mail       : nsierra-@student.42.fr
#          (   /  ,|...-'
#           \_/^\/||__
#        _/~  `""~`"` \_
#     __/  -'/  `-._ `\_\__
#   /jgs  /-'`  `\   \  \--\

NAME				=	metro

SRC_DIR				=	src/
INC_DIR				=	inc/

CLASS_SRC_SUFFIX	=	.cpp
CLASS_INC_SUFFIX	=	.hpp
CLASSES				=	StateManager \
						Engine \
						Logger \
						BoundingBox \
						Transformable \
						BasicObject

ABSTR_SRC_SUFFIX	=	.cpp
ABSTR_INC_SUFFIX	=	.hpp
ABSTRACTS			=	AGameState \
						AObjectPlugin

TEMPL_SRC_SUFFIX	=	.cpp
TEMPL_INC_SUFFIX	=	.hpp
TEMPLATES			=

STATES				=	Test
STATES_FOLDER		=	states/
STATES_SRC			=	$(addsuffix .cpp, $(addprefix $(STATES_FOLDER), $(STATES)))

INC_FILES			=	$(addsuffix $(CLASS_INC_SUFFIX), $(CLASSES))		\
						$(addsuffix $(INTERF_INC_SUFFIX), $(INTERFACES))	\
						$(addsuffix $(ABSTR_INC_SUFFIX), $(ABSTRACTS))		\
						$(addsuffix $(TEMPL_INC_SUFFIX), $(TEMPLATES))

SRC_FILES			=	$(addsuffix $(CLASS_SRC_SUFFIX), $(CLASSES))		\
						$(addsuffix $(INTERF_SRC_SUFFIX), $(INTERFACES))	\
						$(addsuffix $(ABSTR_SRC_SUFFIX), $(ABSTRACTS))		\
						$(addsuffix $(TEMPL_SRC_SUFFIX), $(TEMPLATES))		\
						main.cpp

SRC					=	$(addprefix $(SRC_DIR), $(SRC_FILES)) \
						$(STATES_SRC)
INC					=	$(addprefix $(INC_DIR), $(INC_FILES))

OBJ					=	$(SRC:.cpp=.o)

CC					=	clang++
MAKE				=	make

CFLAGS				=	-Wall -Wextra -Werror -std=c++11 -stdlib=libc++ #-g3
IFLAGS				=	-I./$(INC_DIR) -I./$(STATES_FOLDER) -F/Library/Frameworks #-I./SFML/include
LDFLAGS				=	-F/Library/Frameworks -framework sfml-graphics -framework sfml-window -framework sfml-system

$(NAME):			$(INC) $(OBJ)
					$(CC) $(LDFLAGS) $(OBJ) -o $@

all:				$(NAME)

%.o:				%.cpp
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
					rm -f $(OBJ)

fclean:
					rm -f $(OBJ)
					rm -f $(NAME)

re:					fclean all
