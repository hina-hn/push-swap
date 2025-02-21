# プログラム名
NAME = push_swap

# コンパイラとフラグ
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft/includes

# ディレクトリ
SRCDIR = srcs
OBJDIR = objs
LIBFTDIR = libft

# `libft` のライブラリファイル
LIBFT = $(LIBFTDIR)/libft.a

# ソースファイル
SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/parse_args.c \
       $(SRCDIR)/commands/push.c \
       $(SRCDIR)/commands/reverse_rotate.c \
       $(SRCDIR)/commands/rotate.c \
       $(SRCDIR)/commands/swap.c \
	   $(SRCDIR)/sort/sort_three_or_less.c \
	   $(SRCDIR)/sort/sort_stacks.c \
	   $(SRCDIR)/utils/calc_all_push_cost.c \
	   $(SRCDIR)/utils/calc_cost.c \
	   $(SRCDIR)/utils/stack_utils.c \
	   $(SRCDIR)/utils/move_stack.c \
	   $(SRCDIR)/utils/find_node_utils.c

# オブジェクトファイル
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ヘッダファイル
HEADERS = inc/push_swap.h libft/includes/libft.h

# ルール
all: $(LIBFT) $(NAME)

# `push_swap` のコンパイル
$(NAME): $(OBJS) $(LIBFT) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# `libft` のコンパイル
$(LIBFT):
	make -C $(LIBFTDIR)

# `.o` ファイルの生成
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# `objs` ディレクトリ作成
$(OBJDIR):
	mkdir -p $(OBJDIR)

# クリーンアップ
clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all
