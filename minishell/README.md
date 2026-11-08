*This project has been created as part of the 42 curriculum by anurmach, mgumberi.*

# minishell

## Description

`minishell` is a 42 School project whose goal is to build a simplified, working
Unix command-line interpreter (shell) in C, from scratch, without using any
existing shell implementation as a base.

The program reproduces the core behaviour of `bash` closely enough to run
everyday interactive sessions:

- A read–eval loop built on `readline`, complete with command history.
- A tokenizer, syntax validator and recursive-descent parser that turn a raw
  input line into an executable pipeline (handling simple and double quotes,
  operators, and syntax errors).
- Environment variable and quote expansion (`$VAR`, `$?`, `~`-less literal
  handling as per the subject, quote removal rules identical to `bash`).
- A pipeline executor supporting single commands as well as N-command
  pipelines connected with `|`, using `fork`, `pipe`, `dup2` and `execve`.
- Redirections: `<`, `>`, `>>` and heredocs (`<<`) with signal-aware reading.
- Signal handling in interactive mode (`Ctrl-C`, `Ctrl-\`, `Ctrl-D`) matching
  `bash`'s behaviour at the prompt, inside a heredoc, and while a child process
  is running.
- The seven builtins required by the subject, implemented internally (no
  `execve` call for these): `echo` (with `-n`), `cd` (relative and absolute
  paths, `OLDPWD`/`PWD` updates), `pwd`, `export`, `unset`, `env` and `exit`.

The project is split into clear modules — `tokenizer`, `validator`, `parser`,
`expander`, `env`, `builtins`, `executor` and `signals` — each with its own
source directory under `srcs/`, plus a self-contained `libft` used throughout
for memory-safe C string/list utilities.

## Instructions

### Requirements

- A Unix-like OS (Linux / macOS).
- `cc` (or `gcc`/`clang`), `make`.
- The `readline` development library and headers installed
  (e.g. `sudo apt install libreadline-dev` on Debian/Ubuntu, or
  `brew install readline` on macOS).

### Compilation

```sh
make
```

This first builds `libft.a` inside `libft/`, then compiles all sources in
`srcs/` and links against `readline`, producing the `minishell` executable at
the project root.

Other Makefile targets:

```sh
make clean   # remove object files (project + libft)
make fclean  # clean + remove minishell and libft.a
make re      # fclean + all
```

### Running

```sh
./minishell
```

This starts an interactive prompt (`minishell$ `). Type any shell command,
pipeline or redirection as you would in `bash`:

```sh
minishell$ echo "hello world" | grep hello
minishell$ ls -l > out.txt
minishell$ cat << EOF
heredoc> some text
heredoc> EOF
minishell$ export FOO=bar && echo $FOO
minishell$ exit
```

`minishell` also accepts piped/non-interactive input (e.g.
`echo 'pwd' | ./minishell`), reading commands silently in that case.

## Resources

### Documentation / manuals consulted

The following man pages (sections 1, 2 and 3) were the primary reference
throughout development, for both the syscalls/library calls allowed by the
subject and their exact error-handling semantics:

`readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`,
`rl_redisplay`, `add_history`, `printf`, `malloc`, `free`, `write`, `access`,
`open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`,
`signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`, `getcwd`,
`chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`,
`opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`,
`ttyslot`.

### Articles / tutorials

- [Code-Vault — Minishell lesson](https://code-vault.net/lesson/c5746b15bc917ba13615a0ec8c0011c1) —
  video walkthrough used as a reference for the overall architecture (parsing
  pipeline, process forking and redirection handling).
- The GNU Readline Library and GNU Bash Reference manuals, for the expected
  behaviour of history/line-editing and shell grammar/expansion rules.
- The Bash source code and POSIX shell command language specification, used
  as a behavioural reference when clarifying edge cases in quoting,
  expansion and exit-status rules.

### AI usage

An AI assistant (Claude) was used during this project strictly as a support
tool, in ways that keep the design and implementation decisions with the
authors:

- **Debugging help**: explaining segmentation faults and memory leaks found
  via `valgrind`/`gdb` output and suggesting where to look, without writing
  the fix directly.
- **Concept clarification**: explaining C library/syscall semantics (e.g.
  `dup2`, `waitpid` flags, `sigaction` vs `signal`) and POSIX shell grammar
  rules (quoting, expansion, heredoc) referenced above.
- **Code review**: reviewing already-written functions for edge cases (empty
  commands, unclosed quotes, redirection combinations) and suggesting norm
  compliance improvements.
- **Documentation**: drafting and formatting this README.

No AI tool was used to generate the core parsing, expansion, execution or
signal-handling logic itself; that logic was designed and written by the
project authors.
