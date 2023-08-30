CFLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++\
-Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align\
-Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness\
-Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual\
-Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion\
-Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn\
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default\
-Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast\
-Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing\
-Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation\
-fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer\
-Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla\
-Itests -Isrc\
-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

CC = g++

all : test_strstr_hash
OBJS_NAMES = main.o string.o
OBJDIR = build
OBJS = $(addprefix $(OBJDIR)/, $(OBJS_NAMES))

test_strstr_hash : $(OBJS)
	$(CC) $(CFLAGS) -o test_strstr_hash $(OBJS)

$(OBJDIR)/main.o : main.cpp string.h
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/string.o : string.cpp string.h
	$(CC) $(CFLAGS) -c string.cpp -o $(OBJDIR)/string.o

clean :
	rm test_strstr_hash $(OBJS)
