# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MKDIR = mkdir -p

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft

# Fichiers sources
SRV_SRC = $(SRC_DIR)/server.c
CLI_SRC = $(SRC_DIR)/client.c
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers objets
SRV_OBJ = $(OBJ_DIR)/server.o
CLI_OBJ = $(OBJ_DIR)/client.o

# Noms des exécutables
SRV = server
CLI = client

# Règle par défaut
all: $(LIBFT) $(SRV) $(CLI)

# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilation du serveur
$(SRV): $(SRV_OBJ)
	$(CC) $(CFLAGS) -o $(SRV) $(SRV_OBJ)

# Compilation du client
$(CLI): $(CLI_OBJ)
	$(CC) $(CFLAGS) -o $(CLI) $(CLI_OBJ)

# Création du dossier obj et compilation des fichiers .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Création du dossier obj s'il n'existe pas
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	$(RM) -r $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Nettoyage complet (binaire + objets)
fclean: clean
	$(RM) $(SRV) $(CLI)
	make -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
