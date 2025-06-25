CFILES = main.c

OBJDIR = obj
OFILES = $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

NAME   = push_swap
CC     = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Isrc

MAKEFLAGS += --no-print-directory --silent
LIBFT      = libft/libft.a
P_S        = src/push_swap.a

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;36m
RED     = \033[0;31m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OFILES) $(P_S) $(LIBFT)
	@printf "$(GREEN)» 📦 Linking   $(RESET)» $(MAGENTA)./$(NAME)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFILES) $(P_S) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@printf "$(BLUE)» ⚙️  Compiling $(RESET)» $(YELLOW)%9s$(RESET) | $(GREEN)%s$(RESET)\n" "$<" "$@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): FORCE
	@$(MAKE) -C libft

$(P_S): FORCE
	@$(MAKE) -C src

clean:
	@printf "$(RED)» 🧹 Cleaning  $(RESET)» $(CYAN)./$(OBJDIR) $(RESET)\n"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C libft clean
	@$(MAKE) -C src clean

fclean: clean
	@printf "$(RED)» 🔥 Removing  $(RESET)» $(MAGENTA)./$(NAME)$(RESET)\n"
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C src fclean

re: fclean all

FORCE:
.PHONY: all clean fclean re FORCE