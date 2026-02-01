# === Configuration ===
CXX      = g++
INCLUDES = -I./include -I./test

# === Cibles ===
EXEC_MAIN = main
EXEC_TEST = testClass
EXEC_MKDIR_BUILD = folder_build 


# === Fichier objet ===
#chemin d'accès :
OBJ_DIR   = ./build

#fichier nécessaire au 2
OBJS_BOTH = $(OBJ_DIR)/forme.o $(OBJ_DIR)/point.o 

#fichier néssesaire au main
OBJS_MAIN   = $(OBJ_DIR)/main.o  $(OBJS_BOTH)
#fichier néssesaire au test
OBJS_TEST   = $(OBJ_DIR)/testClass.o $(OBJ_DIR)/unity.o  $(OBJS_BOTH)


# === Régles ===

all: $(EXEC_MKDIR_BUILD) $(EXEC_MAIN)  $(EXEC_TEST)

 #Création du fichier build
$(EXEC_MKDIR_BUILD):
	mkdir -p build 

#link des fichier .o du main					
$(EXEC_MAIN): $(OBJS_MAIN)					
	$(CXX) -o $(EXEC_MAIN) $(OBJS_MAIN)		

#Equivalent 
#$(EXEC_MAIN): $(OBJS_MAIN)		
#	$(CXX) -o $@ $^			

#link des fichier .o du test					
$(EXEC_TEST): $(OBJS_TEST)
	$(CXX) -o $@ $^


# === Compilation ===

# Compilation des fichiers (générale)
# On dit à Make où chercher les fichiers sources (.cpp et .c)
vpath %.cpp ./src  ./src/formeSpecifique  ./test .
$(OBJ_DIR)/%.o: %.cpp 
# $< correspond à la source '%.cpp' (ex :main.cpp) 
# $@ correspond à la target '$(OBJ_DIR)/%' (ex : ./build/main.o)
	$(CXX) $(INCLUDES) -c $< -o $@ 

# Compilation des fichiers (unity)
# règle spécifique pour Unity (car c'est du .c)
vpath %.c ./test
$(OBJ_DIR)/%.o: %.c 
	$(CXX) $(INCLUDES) -c $< -o $@




# === clean ===
#Supprime les fichiers objets et l'exécutable
clean:
	rm -f -R build/
	rm -f $(EXEC_MAIN) $(EXEC_TEST)

.PHONY: all clean



## OLD Version :
# # === Variables ===
# EXEC_PROGRAM1 = folder_build
# EXEC_PROGRAM2 = main
# EXEC_PROGRAM3 = testClass


# # === Règles ===

# all: $(EXEC_PROGRAM1) $(EXEC_PROGRAM2)  $(EXEC_PROGRAM3)
 
# # Compilation de l'exécutable

# $(EXEC_PROGRAM1): 
# 	mkdir -p build

# $(EXEC_PROGRAM2): ./build/main.o ./build/class.o  
# 	g++ -o $(EXEC_PROGRAM2) ./build/main.o ./build/class.o  

# $(EXEC_PROGRAM3): ./build/testClass.o ./build/class.o   ./build/unity.o
# 	g++ -o $(EXEC_PROGRAM3) ./build/testClass.o ./build/class.o  ./build/unity.o


# # Compilation des fichiers sources en fichiers objets
# ./build/main.o: ./main.cpp
# 	g++ -I./include -c ./main.cpp -o ./build/main.o

# ./build/class.o: ./src/class.cpp
# 	g++ -I./include -c ./src/class.cpp -o ./build/class.o


# #Cmpilation de Unity et testClass
# ./build/unity.o: ./test/unity.c
# 	g++ -I./include -c ./test/unity.c -o ./build/unity.o	

# ./build/testClass.o: ./test/testClass.cpp
# 	g++ -I./include -c ./test/testClass.cpp -o ./build/testClass.o


# # Supprime les fichiers objets et l'exécutable
# clean:
# 	rm -f build/*.o
# 	rm -f $(EXEC_PROGRAM1) $(EXEC_PROGRAM2) $(EXEC_PROGRAM3)

# .PHONY: all clean

