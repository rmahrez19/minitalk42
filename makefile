# Variables
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
NAME        = my_project
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes
MKDIR       = mkdir -p   # Définir la commande mkdir pour créer des répertoires

# Fichiers sources
SRV_SRC     = $(SRC_DIR)/server.c $(SRC_DIR)/utils.c
CLI_SRC     = $(SRC_DIR)/client.c $(SRC_DIR)/utils.c

# Fichiers objets
SRV_OBJ     = $(OBJ_DIR)/server.o $(OBJ_DIR)/utils.o
CLI_OBJ     = $(OBJ_DIR)/client.o $(OBJ_DIR)/utils.o

# Noms des exécutables
SRV         = server
CLI         = client

# Règle par défaut
all: $(SRV) $(CLI)

# Compilation du serveur
$(SRV): $(SRV_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SRV) $(SRV_OBJ) $(LIBFT)

# Compilation du client
$(CLI): $(CLI_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLI) $(CLI_OBJ) $(LIBFT)

# Compilation des fichiers .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Création du dossier obj s'il n'existe pas
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_DIR)

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
