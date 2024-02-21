#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_parser.h"

void test_tokenize();
void test_tokenize_command_with_special_pipe();
void test_tokenize_pipeline_with_special_pipe();
void test_parse_command_no_arguments();
void test_parse_command_two_arguments();
void test_parse_command_with_empty_input();
void test_parse_command_with_only_spaces();
void test_parse_command_with_spaces_between();
void test_parse_command_with_spaces_before();
void test_parse_command_with_more_than_max_tokens();
void test_parse_pipeline_with_empty_input();
void test_parse_pipeline_with_single_only_pipe();
void test_parse_pipeline_with_starting_pipe();
void test_parse_pipeline_with_final_pipe();
void test_parse_pipeline_with_wrong_spaces_between_pipe();
void test_parse_pipeline_with_empty_commands_between_pipe();
void test_parse_pipeline_with_correct_pipeline_without_redirection();
void test_parse_pipeline_with_correct_pipeline_with_redirection();
void test_parse_pipeline_list_with_empty_input();
void test_parse_pipeline_list_with_only_spaces();
void test_parse_pipeline_list_with_only_spaces_and_ampersand();
void test_parse_pipeline_list_with_start_ampersand();
void test_parse_pipeline_list_with_middle_ampersands();
void test_parse_pipeline_list_with_only_ampersand();
void test_parse_pipeline_list_with_middle_ampersands_and_spaces();
void test_parse_pipeline_list_with_middle_ampersands_and_spaces2();
void test_parse_pipeline_list_with_single_pipeline_no_job();
void test_parse_pipeline_list_with_single_pipeline_with_job();
void test_parse_pipeline_list_with_correct_pipelines();
void test_parse_pipeline_list_with_correct_pipelines_with_final_ampersand();
void test_parse_pipeline_list_with_correct_pipelines_with_spaces_and_final_ampersand();
void test_parser_command_with_redirections();
void test_parser_command_with_various_redirections();
void test_parser_command_with_correct_but_weird_redirections();
void test_parser_command_with_redirections_and_misleading_arguments();
void test_parser_command_with_redirections_ls_left_arrow();
void test_parser_command_with_redirections_ls_right_arrow();
void test_parser_command_with_redirections_right_arrow();
void test_parser_command_with_redirections_left_arrow();
void test_parser_command_with_redirections_right_arrow_ls();
void test_str_of_pipeline_simple_command();
void test_str_of_pipeline_command_with_stdout_no_truncate_redirection();
void test_str_of_pipeline_command_with_stdin_redirection();
void test_str_of_pipeline_command_with_stdout_concat_redirection();
void test_str_of_pipeline_command_with_stdout_eventual_truncate_redirection();
void test_str_of_pipeline_command_with_stderr_no_truncate_redirection();
void test_str_of_pipeline_command_with_stderr_eventual_truncate_redirection();
void test_str_of_pipeline_command_with_stderr_concat_redirection();
void test_str_of_pipeline_with_stdin_and_stdout_redirection();
void test_str_of_pipeline_with_two_stdout_no_truncate_redirections();
void test_str_of_pipeline_with_three_stdout_no_truncate_redirections();
void test_str_of_pipeline_with_no_truncate_stdout_and_concat_stdout_redirection();
void test_str_of_pipeline_with_no_truncate_stdout_and_no_truncate_stderr_redirection();
void test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stdout_redirection();
void test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stderr_redirection();
void test_str_of_pipeline_with_no_truncate_stdout_and_concat_stderr_redirection();
void test_str_of_pipeline_with_pipe();
void test_str_of_pipeline_with_pipes();
void test_parse_pipeline_with_pipe_substitutions();
void test_parse_pipeline_with_multiple_pipe_substitutions();
void test_parse_pipeline_list_with_pipes_substitutions();
void test_invalid_pipe_substitution1();
void test_invalid_pipe_substitution2();
void test_invalid_pipe_substitution3();
void test_invalid_pipe_substitution4();
void test_invalid_pipe_substitution5();

void test_parser_utils() {
    printf("Test function test_tokenize\n");
    test_tokenize();
    printf("Test test_tokenize passed\n");

    printf("Test function test_tokenize_command_with_special_pipe\n");
    test_tokenize_command_with_special_pipe();
    printf("Test test_tokenize_command_with_special_pipe passed\n");

    printf("Test function test_tokenize_pipeline_with_special_pipe\n");
    test_tokenize_pipeline_with_special_pipe();
    printf("Test test_tokenize_pipeline_with_special_pipe passed\n");

    printf("Test function test_parse_command_no_arguments\n");
    test_parse_command_no_arguments();
    printf("Test test_parse_command_no_arguments passed\n");

    printf("Test function test_parse_command_two_arguments\n");
    test_parse_command_two_arguments();
    printf("Test test_parse_command_two_arguments passed\n");

    printf("Test function parse_command_with_empty_input\n");
    test_parse_command_with_empty_input();
    printf("Test parse_command_with_empty_input passed\n");

    printf("Test function parse_command_with_only_spaces\n");
    test_parse_command_with_only_spaces();
    printf("Test parse_command_with_only_spaces passed\n");

    printf("Test function parse_command_with_spaces_between\n");
    test_parse_command_with_spaces_between();
    printf("Test parse_command_with_spaces_between passed\n");

    printf("Test function parse_command_with_spaces_before\n");
    test_parse_command_with_spaces_before();
    printf("Test parse_command_with_spaces_before passed\n");

    printf("Test function parse_command_with_more_than_max_tokens\n");
    test_parse_command_with_more_than_max_tokens();
    printf("Test parse_command_with_more_than_max_tokens passed\n");

    printf("Test function test_parse_pipeline_with_empty_input\n");
    test_parse_pipeline_with_empty_input();
    printf("Test test_parse_pipeline_with_empty_input passed\n");

    printf("Test function test_parse_pipeline_with_single_only_pipe\n");
    test_parse_pipeline_with_single_only_pipe();
    printf("Test test_parse_pipeline_with_single_only_pipe passed\n");

    printf("Test function test_parse_pipeline_with_starting_pipe\n");
    test_parse_pipeline_with_starting_pipe();
    printf("Test test_parse_pipeline_with_starting_pipe passed\n");

    printf("Test function test_parse_pipeline_with_final_pipe\n");
    test_parse_pipeline_with_final_pipe();
    printf("Test test_parse_pipeline_with_final_pipe passed\n");

    printf("Test function test_parse_pipeline_with_empty_commands_between_pipe\n");
    test_parse_pipeline_with_empty_commands_between_pipe();
    printf("Test test_parse_pipeline_with_empty_commands_between_pipe passed\n");

    printf("Test function test_parse_pipeline_with_correct_pipeline_without_redirection\n");
    test_parse_pipeline_with_correct_pipeline_without_redirection();
    printf("Test test_parse_pipeline_with_correct_pipeline_without_redirection passed\n");

    printf("Test function test_parse_pipeline_with_correct_pipeline_with_redirection\n");
    test_parse_pipeline_with_correct_pipeline_with_redirection();
    printf("Test test_parse_pipeline_with_correct_pipeline_with_redirection passed\n");

    printf("Test function test_parse_pipeline_list_with_empty_input\n");
    test_parse_pipeline_list_with_empty_input();
    printf("Test test_parse_pipeline_list_with_empty_input passed\n");

    printf("Test function test_parse_pipeline_list_with_only_spaces\n");
    test_parse_pipeline_list_with_only_spaces();
    printf("Test test_parse_pipeline_list_with_only_spaces passed\n");

    printf("Test function test_parse_pipeline_list_with_only_ampersand\n");
    test_parse_pipeline_list_with_only_ampersand();
    printf("Test test_parse_pipeline_list_with_only_ampersand passed\n");

    printf("Test function test_parse_pipeline_list_with_only_spaces_and_ampersand\n");
    test_parse_pipeline_list_with_only_spaces_and_ampersand();
    printf("Test test_parse_pipeline_list_with_only_spaces_and_ampersand passed\n");

    printf("Test function test_parse_pipeline_list_with_start_ampersand\n");
    test_parse_pipeline_list_with_start_ampersand();
    printf("Test test_parse_pipeline_list_with_start_ampersand passed\n");

    printf("Test function test_parse_pipeline_list_with_middle_ampersands\n");
    test_parse_pipeline_list_with_middle_ampersands();
    printf("Test test_parse_pipeline_list_with_middle_ampersands passed\n");

    printf("Test function test_parse_pipeline_list_with_middle_ampersands_and_spaces\n");
    test_parse_pipeline_list_with_middle_ampersands_and_spaces();
    printf("Test test_parse_pipeline_list_with_middle_ampersands_and_spaces passed\n");

    printf("Test function test_parse_pipeline_list_with_middle_ampersands_and_spaces2\n");
    test_parse_pipeline_list_with_middle_ampersands_and_spaces2();
    printf("Test test_parse_pipeline_list_with_middle_ampersands_and_spaces2 passed\n");

    printf("Test function test_parse_pipeline_list_with_single_pipeline_with_job\n");
    test_parse_pipeline_list_with_single_pipeline_with_job();
    printf("Test test_parse_pipeline_list_with_single_pipeline_with_job passed\n");

    printf("Test function test_parse_pipeline_list_with_single_pipeline_no_job\n");
    test_parse_pipeline_list_with_single_pipeline_no_job();
    printf("Test test_parse_pipeline_list_with_single_pipeline_no_job passed\n");

    printf("Test function test_parse_pipeline_list_with_correct_pipelines\n");
    test_parse_pipeline_list_with_correct_pipelines();
    printf("Test test_parse_pipeline_list_with_correct_pipelines passed\n");

    printf("Test function test_parse_pipeline_list_with_correct_pipelines_with_final_ampersand\n");
    test_parse_pipeline_list_with_correct_pipelines_with_final_ampersand();
    printf("Test test_parse_pipeline_list_with_correct_pipelines_with_final_ampersand passed\n");

    printf("Test function test_parse_pipeline_list_with_correct_pipelines_with_spaces_and_final_ampersand\n");
    test_parse_pipeline_list_with_correct_pipelines_with_spaces_and_final_ampersand();
    printf("Test test_parse_pipeline_list_with_correct_pipelines_with_spaces_and_final_ampersand passed\n");
    
    printf("Test function test_parser_command_with_redirections\n");
    test_parser_command_with_redirections();
    printf("Test test_parser_command_with_redirections passed\n");

    printf("Test function test_parser_command_with_various_redirections\n");
    test_parser_command_with_various_redirections();
    printf("Test test_parser_command_with_various_redirections passed\n");

    printf("Test function test_parser_command_with_correct_but_weird_redirections\n");
    test_parser_command_with_correct_but_weird_redirections();
    printf("Test test_parser_command_with_correct_but_weird_redirections passed\n");

    printf("Test function test_parser_command_with_redirections_and_misleading_arguments\n");
    test_parser_command_with_redirections_and_misleading_arguments();
    printf("Test test_parser_command_with_redirections_and_misleading_arguments passed\n");

    printf("Test function test_parser_command_with_redirections_ls_left_arrow\n");
    test_parser_command_with_redirections_ls_left_arrow();
    printf("Test test_parser_command_with_redirections_ls_left_arrow passed\n");

    printf("Test function test_parser_command_with_redirections_ls_right_arrow\n");
    test_parser_command_with_redirections_ls_right_arrow();
    printf("Test test_parser_command_with_redirections_ls_right_arrow passed\n");

    printf("Test function test_parser_command_with_redirections_right_arrow\n");
    test_parser_command_with_redirections_right_arrow();
    printf("Test test_parser_command_with_redirections_right_arrow passed\n");

    printf("Test function test_parser_command_with_redirections_left_arrow\n");
    test_parser_command_with_redirections_left_arrow();
    printf("Test test_parser_command_with_redirections_left_arrow passed\n");

    printf("Test function test_parser_command_with_redirections_right_arrow_ls\n");
    test_parser_command_with_redirections_right_arrow_ls();
    printf("Test test_parser_command_with_redirections_right_arrow_ls passed\n");
    
    printf("Test function test_str_of_pipeline_simple_command\n");
    test_str_of_pipeline_simple_command();
    printf("Test test_str_of_pipeline_simple_command passed\n");

    printf("Test function test_str_of_pipeline_command_with_stdout_no_truncate_redirection\n");
    test_str_of_pipeline_command_with_stdout_no_truncate_redirection();
    printf("Test test_str_of_pipeline_command_with_stdout_no_truncate_redirection passed\n");

    printf("Test function test_str_of_pipeline_command_with_stdin_redirection\n");
    test_str_of_pipeline_command_with_stdin_redirection();
    printf("Test test_str_of_pipeline_command_with_stdin_redirection passed_b\n");

    printf("Test function test_str_of_pipeline_command_with_stdout_concat_redirection\n");
    test_str_of_pipeline_command_with_stdout_concat_redirection();
    printf("Test test_str_of_pipeline_command_with_stdout_concat_redirection passed_c\n");

    printf("Test function test_str_of_pipeline_command_with_stdout_eventual_truncate_redirection\n");
    test_str_of_pipeline_command_with_stdout_eventual_truncate_redirection();
    printf("Test test_str_of_pipeline_command_with_stdout_eventual_truncate_redirection passed_d\n");

    printf("Test function test_str_of_pipeline_command_with_stderr_no_truncate_redirection\n");
    test_str_of_pipeline_command_with_stderr_no_truncate_redirection();
    printf("Test test_str_of_pipeline_command_with_stderr_no_truncate_redirection passed_e\n");

    printf("Test function test_str_of_pipeline_command_with_stderr_eventual_truncate_redirection\n");
    test_str_of_pipeline_command_with_stderr_eventual_truncate_redirection();
    printf("Test test_str_of_pipeline_command_with_stderr_eventual_truncate_redirection passed_f\n");

    printf("Test function test_str_of_pipeline_command_with_stderr_concat_redirection\n");
    test_str_of_pipeline_command_with_stderr_concat_redirection();
    printf("Test test_str_of_pipeline_command_with_stderr_concat_redirection passed_g\n");

    printf("Test function test_str_of_pipeline_with_stdin_and_stdout_redirection\n");
    test_str_of_pipeline_with_stdin_and_stdout_redirection();
    printf("Test test_str_of_pipeline_with_stdin_and_stdout_redirection passed\n");

    printf("Test function test_str_of_pipeline_with_two_stdout_no_truncate_redirections\n");
    test_str_of_pipeline_with_two_stdout_no_truncate_redirections();
    printf("Test test_str_of_pipeline_with_two_stdout_no_truncate_redirections passed\n");

    printf("Test function test_str_of_pipeline_with_three_stdout_no_truncate_redirections\n");
    test_str_of_pipeline_with_three_stdout_no_truncate_redirections();
    printf("Test test_str_of_pipeline_with_three_stdout_no_truncate_redirections passed\n");

    printf("Test function test_str_of_pipeline_with_no_truncate_stdout_and_concat_stdout_redirection\n");
    test_str_of_pipeline_with_no_truncate_stdout_and_concat_stdout_redirection();
    printf("Test test_str_of_pipeline_with_no_truncate_stdout_and_concat_stdout_redirection passed\n");

    printf("Test function test_str_of_pipeline_with_no_truncate_stdout_and_no_truncate_stderr_redirection\n");
    test_str_of_pipeline_with_no_truncate_stdout_and_no_truncate_stderr_redirection();
    printf("Test test_str_of_pipeline_with_no_truncate_stdout_and_no_truncate_stderr_redirection passed\n");

    printf("Test function test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stdout_redirection\n");
    test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stdout_redirection();
    printf("Test test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stdout_redirection passed\n");

    printf("Test function test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stderr_redirection\n");
    test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stderr_redirection();
    printf("Test test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stderr_redirection passed\n");

    printf("Test function test_str_of_pipeline_with_no_truncate_stdout_and_concat_stderr_redirection\n");
    test_str_of_pipeline_with_no_truncate_stdout_and_concat_stderr_redirection();
    printf("Test test_str_of_pipeline_with_no_truncate_stdout_and_concat_stderr_redirection passed\n");

    printf("Test function test_str_of_pipeline_with_pipe\n");
    test_str_of_pipeline_with_pipe();
    printf("Test test_str_of_pipeline_with_pipe passed\n");

    printf("Test function test_str_of_pipeline_with_pipes\n");
    test_str_of_pipeline_with_pipes();
    printf("Test test_str_of_pipeline_with_pipes passed\n");

    printf("Test function test_parse_pipeline_with_pipe_substitutions\n");
    test_parse_pipeline_with_pipe_substitutions();
    printf("Test test_parse_pipeline_with_pipe_substitutions passed\n");

    printf("Test function test_parse_pipeline_with_multiple_pipe_substitutions\n");
    test_parse_pipeline_with_multiple_pipe_substitutions();
    printf("Test test_parse_pipeline_with_multiple_pipe_substitutions passed\n");

    printf("Test function test_parse_pipeline_list_with_pipes_substitutions\n");
    test_parse_pipeline_list_with_pipes_substitutions();
    printf("Test test_parse_pipeline_list_with_pipes_substitutions passed\n");

    printf("Test function test_invalid_pipe_substitution1\n");
    test_invalid_pipe_substitution1();
    printf("Test test_invalid_pipe_substitution1 passed\n");

    printf("Test function test_invalid_pipe_substitution2\n");
    test_invalid_pipe_substitution2();
    printf("Test test_invalid_pipe_substitution2 passed\n");

    printf("Test function test_invalid_pipe_substitution3\n");
    test_invalid_pipe_substitution3();
    printf("Test test_invalid_pipe_substitution3 passed\n");

    printf("Test function test_invalid_pipe_substitution4\n");
    test_invalid_pipe_substitution4();
    printf("Test test_invalid_pipe_substitution4 passed\n");

    printf("Test function test_invalid_pipe_substitution5\n");
    test_invalid_pipe_substitution5();
    printf("Test test_invalid_pipe_substitution5 passed\n");    
}

void test_tokenize() {

    size_t token_count;
    char **tokens = tokenize("test of tokenize", &token_count, " ");
    assert(token_count == 3);
    assert(strcmp("test", tokens[0]) == 0);
    assert(strcmp("of", tokens[1]) == 0);
    assert(strcmp("tokenize", tokens[2]) == 0);

    free_tokens(tokens, token_count);

    tokens = tokenize("test|of|tokenize|12||", &token_count, "|");
    assert(token_count == 4);
    assert(strcmp("test", tokens[0]) == 0);
    assert(strcmp("of", tokens[1]) == 0);
    assert(strcmp("tokenize", tokens[2]) == 0);
    assert(strcmp("12", tokens[3]) == 0);

    free_tokens(tokens, token_count);
}

void test_tokenize_command_with_special_pipe() {

    size_t token_count;
    char **tokens = tokenize_command_with_special_pipe("cmd1 arg1 <( cmd2 arg2 | cmd3 ) 2> test", &token_count);
    assert(token_count == 5);
    assert(strcmp("cmd1", tokens[0]) == 0);
    assert(strcmp("arg1", tokens[1]) == 0);
    assert(strcmp("<( cmd2 arg2 | cmd3 )", tokens[2]) == 0);
    assert(strcmp("2>", tokens[3]) == 0);
    assert(strcmp("test", tokens[4]) == 0);

    free_tokens(tokens, token_count);

    tokens = tokenize_command_with_special_pipe("cmd1 arg1 <( cmd2 arg2 | cmd3 ) 2> test <( cmd4 | cmd5 )", &token_count);
    assert(token_count == 6);
    assert(strcmp("cmd1", tokens[0]) == 0);
    assert(strcmp("arg1", tokens[1]) == 0);
    assert(strcmp("<( cmd2 arg2 | cmd3 )", tokens[2]) == 0);
    assert(strcmp("2>", tokens[3]) == 0);
    assert(strcmp("test", tokens[4]) == 0);
    assert(strcmp("<( cmd4 | cmd5 )", tokens[5]) == 0);

    free_tokens(tokens, token_count);
}

void test_tokenize_pipeline_with_special_pipe() {
    
    size_t token_count;
    char** tokens = tokenize_pipeline_with_special_pipe("test | of | tokenize", &token_count);
    assert(token_count == 3);
    assert(strcmp("test", tokens[0]) == 0);
    assert(strcmp("of", tokens[1]) == 0);
    assert(strcmp("tokenize", tokens[2]) == 0);

    free_tokens(tokens, token_count);
    
    tokens = tokenize_pipeline_with_special_pipe("| tedvfd| est |  |of | tokenize | ", &token_count);
    assert(token_count == 3);
    assert(strcmp("| tedvfd| est", tokens[0]) == 0);
    assert(strcmp(" |of", tokens[1]) == 0);
    assert(strcmp("tokenize", tokens[2]) == 0);

    free_tokens(tokens, token_count);

    tokens = tokenize_pipeline_with_special_pipe("| tedvfd| est|  |of |tokenize |", &token_count);
    assert(token_count == 1);
    assert(strcmp("| tedvfd| est|  |of |tokenize |", tokens[0]) == 0);

    free_tokens(tokens, token_count);
    
    tokens = tokenize_pipeline_with_special_pipe("", &token_count);
    assert(token_count == 0);
    free(tokens);

    tokens = tokenize_pipeline_with_special_pipe(" |  |  |  | ", &token_count);
    assert(token_count == 0);
    free(tokens);
}

void test_parse_command_no_arguments() {
    char *input = "ls";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 1);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);
    
    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    // Clean up
    free_command(cmd);
}

void test_parse_command_two_arguments() {
    char *input = "ls -l /home";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 3);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);
    
    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[1]->value.simple, "-l") == 0);

    assert(cmd->argv[2] != NULL);
    assert(cmd->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[2]->value.simple, "/home") == 0);

    assert(cmd->argv[3] == NULL);

    // Clean up
    free_command(cmd);
}

void test_parse_command_with_empty_input() {
    char *input = "";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is NULL
    assert(cmd->name == NULL);

    // Check the correct number of arguments
    assert(cmd->argc == 0);

    // Check if the arguments are NULL
    assert(cmd->argv == NULL);

    // Clean up
    free_command(cmd);
}

void test_parse_command_with_only_spaces() {
    char *input = "     ";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is NULL
    assert(cmd->name == NULL);

    // Check the correct number of arguments
    assert(cmd->argc == 0);

    // Check if the arguments are NULL
    assert(cmd->argv == NULL);

    // Clean up
    free_command(cmd);
}

void test_parse_command_with_spaces_between() {
    char *input = "ls     -l     /home";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 3);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);

    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[1]->value.simple, "-l") == 0);

    assert(cmd->argv[2] != NULL);
    assert(cmd->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[2]->value.simple, "/home") == 0);

    assert(cmd->argv[3] == NULL);

    // Clean up
    free_command(cmd);
}

void test_parse_command_with_spaces_before() {
    char *input = "     ls -l /home";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 3);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);

    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[1]->value.simple, "-l") == 0);

    assert(cmd->argv[2] != NULL);
    assert(cmd->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[2]->value.simple, "/home") == 0);

    // Clean up
    free_command(cmd);
}

void test_parse_command_with_more_than_max_tokens() {
    // Create a string with more than MAX_TOKENS tokens dynamically
    size_t token_count = 2 * MAX_TOKENS;
    char *input = malloc(sizeof(char) * (token_count * 2 + 1));
    if (input == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    // Fill the input with "a " token_count times
    size_t i = 0;
    for (i = 0; i < token_count; ++i) {
        input[i * 2] = 'a';
        input[i * 2 + 1] = ' ';
    }
    input[token_count * 2] = '\0';

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "a") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == MAX_TOKENS);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);

    for (i = 0; i < MAX_TOKENS; ++i) {
        assert(cmd->argv[i] != NULL);
        assert(cmd->argv[i]->type == ARG_SIMPLE);
        assert(strcmp(cmd->argv[i]->value.simple, "a") == 0);
    }

    assert(cmd->argv[MAX_TOKENS] == NULL);

    // Clean up
    free_command(cmd);
    free(input);
}

void test_parse_pipeline_with_empty_input() {
    char *input = "";

    // Call the function to test
    pipeline *pip = parse_pipeline(input, true);

    // Check if the commands of pipeline is NULL
    assert(pip->commands == NULL);

    // Check the correct number of commands
    assert(pip->command_count == 0);

    // Check the correct value of to_job
    assert(pip->to_job);

    // Clean up
    free_pipeline(pip);
}

void test_parse_pipeline_with_single_only_pipe() {
    char *input = "|";

    // Call the function to test
    pipeline *pip = parse_pipeline(input, true);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}

void test_parse_pipeline_with_final_pipe() {
    char *input = "ls | ls |";

    // Call the function to test
    pipeline *pip = parse_pipeline(input, true);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}

void test_parse_pipeline_with_starting_pipe() {
    char *input = "| ls | ls";

    // Call the function to test
    pipeline *pip = parse_pipeline(input, true);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}

void test_parse_pipeline_with_empty_commands_between_pipe() {
    char *input1 = "ls | ";
    char *input2 = "ls |  | ls";
    char *input3 = "  | ls |ls | ls";
    char *input4 = "ls | ls| | ls";

    // Call the function to test
    pipeline *pip1 = parse_pipeline(input1, true);
    pipeline *pip2 = parse_pipeline(input2, true);
    pipeline *pip3 = parse_pipeline(input3, true);
    pipeline *pip4 = parse_pipeline(input4, true);

    // Check if the pipeline is NULL
    assert(pip1 == NULL);
    assert(pip2 == NULL);
    assert(pip3 == NULL);
    assert(pip4 == NULL);
}

void test_parse_pipeline_with_correct_pipeline_without_redirection() {
    char *input1 = "ls | wc -l";
    char *input2 = "cmd1 arg1 | cmd2 arg1 arg2 | cmd3 | cmd4 arg1 | cmd5 arg1 arg2 arg3";

    // Call the function to test
    pipeline *pip1 = parse_pipeline(input1, true);
    pipeline *pip2 = parse_pipeline(input2, true);

    // Check the correct number of command
    assert(pip1->command_count == 2);
    assert(pip2->command_count == 5);

    // Check the correct names of commands
    assert(strcmp(pip1->commands[0]->name, "ls") == 0);
    assert(strcmp(pip1->commands[1]->name, "wc") == 0);

    assert(strcmp(pip2->commands[0]->name, "cmd1") == 0);
    assert(strcmp(pip2->commands[1]->name, "cmd2") == 0);
    assert(strcmp(pip2->commands[2]->name, "cmd3") == 0);
    assert(strcmp(pip2->commands[3]->name, "cmd4") == 0);
    assert(strcmp(pip2->commands[4]->name, "cmd5") == 0);

    // Check the correct number of args of commands
    assert(pip1->commands[0]->argc == 1);
    assert(pip1->commands[1]->argc == 2);

    assert(pip2->commands[0]->argc == 2);
    assert(pip2->commands[1]->argc == 3);
    assert(pip2->commands[2]->argc == 1);
    assert(pip2->commands[3]->argc == 2);
    assert(pip2->commands[4]->argc == 4);

    // Check the correct value of args of commands
    assert(pip1->commands[0]->argv != NULL);
    assert(pip1->commands[0]->argv[0] != NULL);
    assert(pip1->commands[0]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip1->commands[0]->argv[0]->value.simple, "ls") == 0);
    assert(pip1->commands[0]->argv[1] == NULL);
    

    assert(pip1->commands[1]->argv != NULL);
    assert(pip1->commands[1]->argv[0] != NULL);
    assert(pip1->commands[1]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip1->commands[1]->argv[0]->value.simple, "wc") == 0);
    assert(pip1->commands[1]->argv[1] != NULL);
    assert(pip1->commands[1]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip1->commands[1]->argv[1]->value.simple, "-l") == 0);
    assert(pip1->commands[1]->argv[2] == NULL);

    assert(pip2->commands[0]->argv != NULL);
    assert(pip2->commands[0]->argv[0] != NULL);
    assert(pip2->commands[0]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[0]->argv[0]->value.simple, "cmd1") == 0);
    assert(pip2->commands[0]->argv[1] != NULL);
    assert(pip2->commands[0]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[0]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[0]->argv[2] == NULL);

    assert(pip2->commands[1]->argv != NULL);
    assert(pip2->commands[1]->argv[0] != NULL);
    assert(pip2->commands[1]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[1]->argv[0]->value.simple, "cmd2") == 0);
    assert(pip2->commands[1]->argv[1] != NULL);
    assert(pip2->commands[1]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[1]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[1]->argv[2] != NULL);
    assert(pip2->commands[1]->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[1]->argv[2]->value.simple, "arg2") == 0);
    assert(pip2->commands[1]->argv[3] == NULL);

    assert(pip2->commands[2]->argv != NULL);
    assert(pip2->commands[2]->argv[0] != NULL);
    assert(pip2->commands[2]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[2]->argv[0]->value.simple, "cmd3") == 0);
    assert(pip2->commands[2]->argv[1] == NULL);

    assert(pip2->commands[3]->argv != NULL);
    assert(pip2->commands[3]->argv[0] != NULL);
    assert(pip2->commands[3]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[3]->argv[0]->value.simple, "cmd4") == 0);
    assert(pip2->commands[3]->argv[1] != NULL);
    assert(pip2->commands[3]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[3]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[3]->argv[2] == NULL);

    assert(pip2->commands[4]->argv != NULL);
    assert(pip2->commands[4]->argv[0] != NULL);
    assert(pip2->commands[4]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[0]->value.simple, "cmd5") == 0);
    assert(pip2->commands[4]->argv[1] != NULL);
    assert(pip2->commands[4]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[4]->argv[2] != NULL);
    assert(pip2->commands[4]->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[2]->value.simple, "arg2") == 0);
    assert(pip2->commands[4]->argv[3] != NULL);
    assert(pip2->commands[4]->argv[3]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[3]->value.simple, "arg3") == 0);
    assert(pip2->commands[4]->argv[4] == NULL);

    // Check the correct value of to_job
    assert(pip1->to_job);
    assert(pip2->to_job);

    free_pipeline(pip1);
    free_pipeline(pip2);
}

void test_parse_pipeline_with_correct_pipeline_with_redirection() {
    char *input1 = "ls | wc -l > t 2> t2";
    char *input2 = "cmd1 arg1 2> t1 | cmd2 arg1 arg2 2>| t2 | cmd3 | cmd4 arg1 < t4 | cmd5 arg1 arg2 arg3 > t5 2> t6";

    // Call the function to test
    pipeline *pip1 = parse_pipeline(input1, true);
    pipeline *pip2 = parse_pipeline(input2, true);

    // Check the correct number of command
    assert(pip1->command_count == 2);
    assert(pip2->command_count == 5);

    // Check the correct names of commands
    assert(strcmp(pip1->commands[0]->name, "ls") == 0);
    assert(strcmp(pip1->commands[1]->name, "wc") == 0);

    assert(strcmp(pip2->commands[0]->name, "cmd1") == 0);
    assert(strcmp(pip2->commands[1]->name, "cmd2") == 0);
    assert(strcmp(pip2->commands[2]->name, "cmd3") == 0);
    assert(strcmp(pip2->commands[3]->name, "cmd4") == 0);
    assert(strcmp(pip2->commands[4]->name, "cmd5") == 0);

    // Check the correct number of args of commands
    assert(pip1->commands[0]->argc == 1);
    assert(pip1->commands[1]->argc == 2);

    assert(pip2->commands[0]->argc == 2);
    assert(pip2->commands[1]->argc == 3);
    assert(pip2->commands[2]->argc == 1);
    assert(pip2->commands[3]->argc == 2);
    assert(pip2->commands[4]->argc == 4);

    // Check the correct value of args of commands
    assert(pip1->commands[0]->argv != NULL);
    assert(pip1->commands[0]->argv[0] != NULL);
    assert(pip1->commands[0]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip1->commands[0]->argv[0]->value.simple, "ls") == 0);
    assert(pip1->commands[0]->argv[1] == NULL);

    assert(pip1->commands[1]->argv != NULL);
    assert(pip1->commands[1]->argv[0] != NULL);
    assert(pip1->commands[1]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip1->commands[1]->argv[0]->value.simple, "wc") == 0);
    assert(pip1->commands[1]->argv[1] != NULL);
    assert(pip1->commands[1]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip1->commands[1]->argv[1]->value.simple, "-l") == 0);
    assert(pip1->commands[1]->argv[2] == NULL);

    assert(pip2->commands[0]->argv != NULL);
    assert(pip2->commands[0]->argv[0] != NULL);
    assert(pip2->commands[0]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[0]->argv[0]->value.simple, "cmd1") == 0);
    assert(pip2->commands[0]->argv[1] != NULL);
    assert(pip2->commands[0]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[0]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[0]->argv[2] == NULL);

    assert(pip2->commands[1]->argv != NULL);
    assert(pip2->commands[1]->argv[0] != NULL);
    assert(pip2->commands[1]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[1]->argv[0]->value.simple, "cmd2") == 0);
    assert(pip2->commands[1]->argv[1] != NULL);
    assert(pip2->commands[1]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[1]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[1]->argv[2] != NULL);
    assert(pip2->commands[1]->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[1]->argv[2]->value.simple, "arg2") == 0);
    assert(pip2->commands[1]->argv[3] == NULL);

    assert(pip2->commands[2]->argv != NULL);
    assert(pip2->commands[2]->argv[0] != NULL);
    assert(pip2->commands[2]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[2]->argv[0]->value.simple, "cmd3") == 0);
    assert(pip2->commands[2]->argv[1] == NULL);

    assert(pip2->commands[3]->argv != NULL);
    assert(pip2->commands[3]->argv[0] != NULL);
    assert(pip2->commands[3]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[3]->argv[0]->value.simple, "cmd4") == 0);
    assert(pip2->commands[3]->argv[1] != NULL);
    assert(pip2->commands[3]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[3]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[3]->argv[2] == NULL);

    assert(pip2->commands[4]->argv != NULL);
    assert(pip2->commands[4]->argv[0] != NULL);
    assert(pip2->commands[4]->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[0]->value.simple, "cmd5") == 0);
    assert(pip2->commands[4]->argv[1] != NULL);
    assert(pip2->commands[4]->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[1]->value.simple, "arg1") == 0);
    assert(pip2->commands[4]->argv[2] != NULL);
    assert(pip2->commands[4]->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[2]->value.simple, "arg2") == 0);
    assert(pip2->commands[4]->argv[3] != NULL);
    assert(pip2->commands[4]->argv[3]->type == ARG_SIMPLE);
    assert(strcmp(pip2->commands[4]->argv[3]->value.simple, "arg3") == 0);
    assert(pip2->commands[4]->argv[4] == NULL);

    // Check the correct number of redirections of commands
    assert(pip1->commands[0]->redirection_count == 0);
    assert(pip1->commands[1]->redirection_count == 2);

    assert(pip2->commands[0]->redirection_count == 1);
    assert(pip2->commands[1]->redirection_count == 1);
    assert(pip2->commands[2]->redirection_count == 0);
    assert(pip2->commands[3]->redirection_count == 1);
    assert(pip2->commands[4]->redirection_count == 2);

    // Check the correct value of redirections of commands
    assert(pip1->commands[1]->redirections[0].mode == REDIRECT_NO_OVERWRITE);
    assert(pip1->commands[1]->redirections[0].type == REDIRECT_STDOUT);
    assert(strcmp(pip1->commands[1]->redirections[0].filename, "t") == 0);
    assert(pip1->commands[1]->redirections[1].mode == REDIRECT_NO_OVERWRITE);
    assert(pip1->commands[1]->redirections[1].type == REDIRECT_STDERR);
    assert(strcmp(pip1->commands[1]->redirections[1].filename, "t2") == 0);

    assert(pip2->commands[0]->redirections[0].mode == REDIRECT_NO_OVERWRITE);
    assert(pip2->commands[0]->redirections[0].type == REDIRECT_STDERR);
    assert(strcmp(pip2->commands[0]->redirections[0].filename, "t1") == 0);
    assert(pip2->commands[1]->redirections[0].mode == REDIRECT_OVERWRITE);
    assert(pip2->commands[1]->redirections[0].type == REDIRECT_STDERR);
    assert(strcmp(pip2->commands[1]->redirections[0].filename, "t2") == 0);
    assert(pip2->commands[3]->redirections[0].mode == REDIRECT_NONE);
    assert(pip2->commands[3]->redirections[0].type == REDIRECT_STDIN);
    assert(strcmp(pip2->commands[3]->redirections[0].filename, "t4") == 0);
    assert(pip2->commands[4]->redirections[0].mode == REDIRECT_NO_OVERWRITE);
    assert(pip2->commands[4]->redirections[0].type == REDIRECT_STDOUT);
    assert(strcmp(pip2->commands[4]->redirections[0].filename, "t5") == 0);
    assert(pip2->commands[4]->redirections[1].mode == REDIRECT_NO_OVERWRITE);
    assert(pip2->commands[4]->redirections[1].type == REDIRECT_STDERR);
    assert(strcmp(pip2->commands[4]->redirections[1].filename, "t6") == 0);

    // Check the correct value of to_job
    assert(pip1->to_job);
    assert(pip2->to_job);

    free_pipeline(pip1);
    free_pipeline(pip2);
}

void test_parse_pipeline_list_with_empty_input() {
    char *input = "";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of pipeline list is NULL
    assert(pips->pipelines == NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 0);

    // Clean up
    free_pipeline_list(pips);
}

void test_parse_pipeline_list_with_only_spaces() {
    char *input = "     ";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of the list is not NULL
    assert(pips->pipelines != NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 1);

    // Check if the pipeline are NULL
    assert(pips->pipelines[0] != NULL);

    assert(pips->pipelines[0]->command_count == 1);

    assert(pips->pipelines[0]->commands[0]->name == NULL);
    // Clean up
    free_pipeline_list(pips);
}

void test_parse_pipeline_list_with_only_ampersand() {
    char *input = "&";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipeline_list name is NULL
    assert(pips == NULL);
}

void test_parse_pipeline_list_with_only_spaces_and_ampersand() {
    char *input = "   &    ";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipeline_list name is NULL
    assert(pips == NULL);
}

void test_parse_pipeline_list_with_start_ampersand() {
    char *input = " & ls";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipeline_list name is NULL
    assert(pips == NULL);
}

void test_parse_pipeline_list_with_middle_ampersands() {
    char *input = "ls && ./test";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipeline_list is NULL
    assert(pips == NULL);
}

void test_parse_pipeline_list_with_middle_ampersands_and_spaces() {
    char *input = "ls &    & ./test";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipeline_list is NULL
    assert(pips == NULL);
}

void test_parse_pipeline_list_with_middle_ampersands_and_spaces2() {
    char *input = "ls &    &";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipeline_list is NULL
    assert(pips == NULL);
}

void test_parse_pipeline_list_with_single_pipeline_no_job() {
    char *input = "ls -l";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of the list is not NULL
    assert(pips->pipelines != NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 1);

    // Call the pipeline to test
    pipeline *pip1 = pips->pipelines[0];

    // Check if the pipeline has not to_job
    assert(!pip1->to_job);

    // Check the correct number of command in pipeline
    assert(pip1->command_count == 1);

    // Call the command to test
    command *cmd1 = pip1->commands[0];

    // Check the correct command name
    assert(strcmp(cmd1->name, "ls") == 0);

    // Check the correct number of args of command
    assert(cmd1->argc == 2);

    // Cleanup
    free_pipeline_list(pips);
}

void test_parse_pipeline_list_with_single_pipeline_with_job() {
    char *input = "ls -l &";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of the list is not NULL
    assert(pips->pipelines != NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 1);

    // Call the pipeline to test
    pipeline *pip1 = pips->pipelines[0];

    // Check if the pipeline has to_job
    assert(pip1->to_job);

    // Check the correct number of command in pipeline
    assert(pip1->command_count == 1);

    // Call the command to test
    command *cmd1 = pip1->commands[0];

    // Check the correct command name
    assert(strcmp(cmd1->name, "ls") == 0);

    // Check the correct number of args of command
    assert(cmd1->argc == 2);

    // Cleanup
    free_pipeline_list(pips);
}

void test_parse_pipeline_list_with_correct_pipelines() {
    char *input = "ls & ./test & ./a.out";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of the list is not NULL
    assert(pips->pipelines != NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 3);

    // Call the pipelines to test
    pipeline *pip1 = pips->pipelines[0];
    pipeline *pip2 = pips->pipelines[1];
    pipeline *pip3 = pips->pipelines[2];

    // Check if the pipelines have to_job or not
    assert(pip1->to_job);
    assert(pip2->to_job);
    assert(!pip3->to_job);

    // Check the correct number of command in pipelines
    assert(pip1->command_count == 1);
    assert(pip2->command_count == 1);
    assert(pip3->command_count == 1);

    // Call the commands to test
    command *cmd1 = pip1->commands[0];
    command *cmd2 = pip2->commands[0];
    command *cmd3 = pip3->commands[0];

    // Check the correct commands name
    assert(strcmp(cmd1->name, "ls") == 0);
    assert(strcmp(cmd2->name, "./test") == 0);
    assert(strcmp(cmd3->name, "./a.out") == 0);

    // Check the correct number of args of commands
    assert(cmd1->argc == 1);
    assert(cmd2->argc == 1);
    assert(cmd3->argc == 1);

    // Cleanup
    free_pipeline_list(pips);
}

void test_parse_pipeline_list_with_correct_pipelines_with_final_ampersand() {
    char *input = "./test t a & ls -l & ./a.out & mkdir t &";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of the list is not NULL
    assert(pips->pipelines != NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 4);

    // Call the pipelines to test
    pipeline *pip1 = pips->pipelines[0];
    pipeline *pip2 = pips->pipelines[1];
    pipeline *pip3 = pips->pipelines[2];
    pipeline *pip4 = pips->pipelines[3];

    // Check if the pipelines have to_job
    assert(pip1->to_job);
    assert(pip2->to_job);
    assert(pip3->to_job);
    assert(pip4->to_job);

    // Check the correct number of command in pipelines
    assert(pip1->command_count == 1);
    assert(pip2->command_count == 1);
    assert(pip3->command_count == 1);
    assert(pip4->command_count == 1);

    // Call the commands to test
    command *cmd1 = pip1->commands[0];
    command *cmd2 = pip2->commands[0];
    command *cmd3 = pip3->commands[0];
    command *cmd4 = pip4->commands[0];

    // Check the correct commands name
    assert(strcmp(cmd1->name, "./test") == 0);
    assert(strcmp(cmd2->name, "ls") == 0);
    assert(strcmp(cmd3->name, "./a.out") == 0);
    assert(strcmp(cmd4->name, "mkdir") == 0);

    // Check the correct number of args of commands
    assert(cmd1->argc == 3);
    assert(cmd2->argc == 2);
    assert(cmd3->argc == 1);
    assert(cmd4->argc == 2);

    // Cleanup
    free_pipeline_list(pips);
}

void test_parse_pipeline_list_with_correct_pipelines_with_spaces_and_final_ampersand() {
    char *input = "  ./test   t  a  &    ls    -l     & ./a.out&mkdir          t    &           ";

    // Call the function to test
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of the list is not NULL
    assert(pips->pipelines != NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 5);

    // Call the pipelines to test
    pipeline *pip1 = pips->pipelines[0];
    pipeline *pip2 = pips->pipelines[1];
    pipeline *pip3 = pips->pipelines[2];
    pipeline *pip4 = pips->pipelines[3];
    pipeline *pip5 = pips->pipelines[4];

    // Check last pipeline

    assert(pip5 != NULL);
    assert(pip5->command_count == 1);
    assert(pip5->commands != NULL);
    assert(pip5->commands[0]->name == NULL);

    // Check if the pipelines have to_job
    assert(pip1->to_job);
    assert(pip2->to_job);
    assert(pip3->to_job);
    assert(pip4->to_job);

    // Check the correct number of command in pipelines
    assert(pip1->command_count == 1);
    assert(pip2->command_count == 1);
    assert(pip3->command_count == 1);
    assert(pip4->command_count == 1);

    // Call the commands to test
    command *cmd1 = pip1->commands[0];
    command *cmd2 = pip2->commands[0];
    command *cmd3 = pip3->commands[0];
    command *cmd4 = pip4->commands[0];

    // Check the correct commands name
    assert(strcmp(cmd1->name, "./test") == 0);
    assert(strcmp(cmd2->name, "ls") == 0);
    assert(strcmp(cmd3->name, "./a.out") == 0);
    assert(strcmp(cmd4->name, "mkdir") == 0);

    // Check the correct number of args of commands
    assert(cmd1->argc == 3);
    assert(cmd2->argc == 2);
    assert(cmd3->argc == 1);
    assert(cmd4->argc == 2);

    // Cleanup
    free_pipeline_list(pips);
}
void test_parser_command_with_redirections() {
    char *input = "ls -l > foo";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 2);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);

    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[1]->value.simple, "-l") == 0);

    assert(cmd->argv[2] == NULL);

    // Check the correct number of redirections
    assert(cmd->redirection_count == 1);

    // Check if the redirections are correct
    assert(cmd->redirections[0].type == REDIRECT_STDOUT);
    assert(cmd->redirections[0].mode == REDIRECT_NO_OVERWRITE);
    assert(strcmp(cmd->redirections[0].filename, "foo") == 0);

    // Clean up
    free_command(cmd);
}

void test_parser_command_with_various_redirections() {
    char *input = "ls -l < foo >| bar fic 2>> baz < iota >> foo 2> bar bar";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 4);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);
    
    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[1]->value.simple, "-l") == 0);

    assert(cmd->argv[2] != NULL);
    assert(cmd->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[2]->value.simple, "fic") == 0);

    assert(cmd->argv[3] != NULL);
    assert(cmd->argv[3]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[3]->value.simple, "bar") == 0);

    assert(cmd->argv[4] == NULL);

    // Check the correct number of redirections
    assert(cmd->redirection_count == 6);

    // Check if the redirections are correct

    assert(cmd->redirections[0].type == REDIRECT_STDIN);
    assert(cmd->redirections[0].mode == REDIRECT_NONE);
    assert(strcmp(cmd->redirections[0].filename, "foo") == 0);

    assert(cmd->redirections[1].type == REDIRECT_STDOUT);
    assert(cmd->redirections[1].mode == REDIRECT_OVERWRITE);
    assert(strcmp(cmd->redirections[1].filename, "bar") == 0);

    assert(cmd->redirections[2].type == REDIRECT_STDERR);
    assert(cmd->redirections[2].mode == REDIRECT_APPEND);
    assert(strcmp(cmd->redirections[2].filename, "baz") == 0);

    assert(cmd->redirections[3].type == REDIRECT_STDIN);
    assert(cmd->redirections[3].mode == REDIRECT_NONE);
    assert(strcmp(cmd->redirections[3].filename, "iota") == 0);

    assert(cmd->redirections[4].type == REDIRECT_STDOUT);
    assert(cmd->redirections[4].mode == REDIRECT_APPEND);
    assert(strcmp(cmd->redirections[4].filename, "foo") == 0);

    assert(cmd->redirections[5].type == REDIRECT_STDERR);
    assert(cmd->redirections[5].mode == REDIRECT_NO_OVERWRITE);
    assert(strcmp(cmd->redirections[5].filename, "bar") == 0);

    // Clean up
    free_command(cmd);
}

void test_parser_command_with_correct_but_weird_redirections() {
    char *input = "ls -l >| foo 2>> bar fic";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 3);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);

    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[1]->value.simple, "-l") == 0);

    assert(cmd->argv[2] != NULL);
    assert(cmd->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[2]->value.simple, "fic") == 0);

    assert(cmd->argv[3] == NULL);

    // Check the correct number of redirections
    assert(cmd->redirection_count == 2);

    // Check if the redirections are correct
    assert(cmd->redirections[0].type == REDIRECT_STDOUT);
    assert(cmd->redirections[0].mode == REDIRECT_OVERWRITE);
    assert(strcmp(cmd->redirections[0].filename, "foo") == 0);

    assert(cmd->redirections[1].type == REDIRECT_STDERR);
    assert(cmd->redirections[1].mode == REDIRECT_APPEND);
    assert(strcmp(cmd->redirections[1].filename, "bar") == 0);

    // Clean up
    free_command(cmd);
}

void test_parser_command_with_redirections_and_misleading_arguments() {
    char *input = "ls -l > foo bar fic 2>> baz < iota >> foo 2> bar bar";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command name is correct
    assert(strcmp(cmd->name, "ls") == 0);

    // Check the correct number of arguments
    assert(cmd->argc == 5);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);

    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "ls") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[1]->value.simple, "-l") == 0);

    assert(cmd->argv[2] != NULL);
    assert(cmd->argv[2]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[2]->value.simple, "bar") == 0);

    assert(cmd->argv[3] != NULL);
    assert(cmd->argv[3]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[3]->value.simple, "fic") == 0);

    assert(cmd->argv[4] != NULL);
    assert(cmd->argv[4]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[4]->value.simple, "bar") == 0);

    assert(cmd->argv[5] == NULL);

    // Check the correct number of redirections
    assert(cmd->redirection_count == 5);

    // Check if the redirections are correct
    assert(cmd->redirections[0].type == REDIRECT_STDOUT);
    assert(cmd->redirections[0].mode == REDIRECT_NO_OVERWRITE);
    assert(strcmp(cmd->redirections[0].filename, "foo") == 0);

    assert(cmd->redirections[1].type == REDIRECT_STDERR);
    assert(cmd->redirections[1].mode == REDIRECT_APPEND);
    assert(strcmp(cmd->redirections[1].filename, "baz") == 0);

    assert(cmd->redirections[2].type == REDIRECT_STDIN);
    assert(cmd->redirections[2].mode == REDIRECT_NONE);
    assert(strcmp(cmd->redirections[2].filename, "iota") == 0);

    assert(cmd->redirections[3].type == REDIRECT_STDOUT);
    assert(cmd->redirections[3].mode == REDIRECT_APPEND);
    assert(strcmp(cmd->redirections[3].filename, "foo") == 0);

    assert(cmd->redirections[4].type == REDIRECT_STDERR);
    assert(cmd->redirections[4].mode == REDIRECT_NO_OVERWRITE);
    assert(strcmp(cmd->redirections[4].filename, "bar") == 0);

    // Clean up
    free_command(cmd);
}

void test_parser_command_with_redirections_ls_left_arrow() {
    char *input = "ls <";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command is NULL
    assert(cmd == NULL);

}

void test_parser_command_with_redirections_ls_right_arrow() {
    char *input = "ls >";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command is NULL
    assert(cmd == NULL);

}

void test_parser_command_with_redirections_right_arrow() {
    char *input = ">";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command is NULL
    assert(cmd == NULL);

}

void test_parser_command_with_redirections_left_arrow() {
    char *input = "<";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command is NULL
    assert(cmd == NULL);

}

void test_parser_command_with_redirections_right_arrow_ls() {
    char *input = "> ls";

    // Call the function to test
    command *cmd = parse_command(input);

    // Check if the command is NULL
    assert(cmd == NULL);

}

void test_str_of_pipeline_simple_command() {
    // Set up
    char *input = "sleep 500";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "sleep 500") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_command_with_stdout_no_truncate_redirection() {
    // Set up
    char *input = "ls > a.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_command_with_stdin_redirection() {
    // Set up
    char *input = "a.out < ls";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "a.out < ls") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_command_with_stdout_concat_redirection() {
    // Set up
    char *input = "ls >> a.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls >> a.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_command_with_stdout_eventual_truncate_redirection() {
    // Set up
    char *input = "ls >| a.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls >| a.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_command_with_stderr_no_truncate_redirection() {
    // Set up
    char *input = "ls 2> a.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls 2> a.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_command_with_stderr_eventual_truncate_redirection() {
    // Set up
    char *input = "ls 2>| a.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls 2>| a.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_command_with_stderr_concat_redirection() {
    // Set up
    char *input = "ls 2>> a.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls 2>> a.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_stdin_and_stdout_redirection() {
    // Set up
    char *input = "z.out < ls > a.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "z.out < ls > a.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_two_stdout_no_truncate_redirections() {
    // Set up
    char *input = "ls > a.out > b.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out > b.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_three_stdout_no_truncate_redirections() {
    // Set up
    char *input = "ls > a.out > b.out > c.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out > b.out > c.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_no_truncate_stdout_and_concat_stdout_redirection() {
    // Set up
    char *input = "ls > a.out >> b.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out >> b.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_no_truncate_stdout_and_no_truncate_stderr_redirection() {
    // Set up
    char *input = "ls > a.out 2> b.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out 2> b.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stdout_redirection() {
    // Set up
    char *input = "ls > a.out >| b.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out >| b.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_no_truncate_stdout_and_eventual_truncate_stderr_redirection() {
    // Set up
    char *input = "ls > a.out 2>| b.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out 2>| b.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_no_truncate_stdout_and_concat_stderr_redirection() {
    // Set up
    char *input = "ls > a.out 2>> b.out";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "ls > a.out 2>> b.out") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_pipe() {
    // Set up
    char *input = "./test1 | ./test2";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "./test1 | ./test2") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_str_of_pipeline_with_pipes() {
    // Set up
    char *input = "./test1 | ./test2 | ./test1";
    pipeline *pip = parse_pipeline(input, true);
    
    // Call the function to test
    char* strpip = str_of_pipeline(pip);

    // Check if the string is correct
    assert(strcmp(strpip, "./test1 | ./test2 | ./test1") == 0);

    // Clean up
    free_pipeline(pip);
    free(strpip);
}

void test_parse_pipeline_with_pipe_substitutions() {
    // Set up
    char *input = "cat <(cat foo | grep bar <(cat baz)) 2> bar";
    pipeline *pip = parse_pipeline(input, false);

    // Check if the pipeline is NULL
    assert(pip != NULL);

    // Check the correct number of commands
    assert(pip->command_count == 1);

    // Call the command to test
    command *cmd = pip->commands[0];

    // Check the correct command name
    assert(strcmp(cmd->name, "cat") == 0);

    // Check the correct number of args of command
    assert(cmd->argc == 2);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);
    
    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "cat") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SUBSTITUTION);
    pipeline *subpip = cmd->argv[1]->value.substitution;

    // Check if the pipeline is NULL
    assert(subpip != NULL);

    // Check the correct number of commands
    assert(subpip->command_count == 2);

    // Call the command to test
    command *subcmd1 = subpip->commands[0];

    // Check the correct command name
    assert(strcmp(subcmd1->name, "cat") == 0);

    // Check the correct number of args of command
    assert(subcmd1->argc == 2);

    // Check if the arguments are correct
    assert(subcmd1->argv != NULL);

    assert(subcmd1->argv[0] != NULL);
    assert(subcmd1->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd1->argv[0]->value.simple, "cat") == 0);

    assert(subcmd1->argv[1] != NULL);
    assert(subcmd1->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd1->argv[1]->value.simple, "foo") == 0);

    assert(subcmd1->argv[2] == NULL);

    // Call the command to test
    command *subcmd2 = subpip->commands[1];

    // Check the correct command name
    assert(strcmp(subcmd2->name, "grep") == 0);

    // Check the correct number of args of command
    assert(subcmd2->argc == 3);

    // Check if the arguments are correct
    assert(subcmd2->argv != NULL);

    assert(subcmd2->argv[0] != NULL);
    assert(subcmd2->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd2->argv[0]->value.simple, "grep") == 0);

    assert(subcmd2->argv[1] != NULL);
    assert(subcmd2->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd2->argv[1]->value.simple, "bar") == 0);

    assert(subcmd2->argv[2] != NULL);
    assert(subcmd2->argv[2]->type == ARG_SUBSTITUTION);
    pipeline *subpip2 = subcmd2->argv[2]->value.substitution;

    // Check if the pipeline is NULL
    assert(subpip2 != NULL);

    // Check the correct number of commands
    assert(subpip2->command_count == 1);

    // Call the command to test
    command *subcmd3 = subpip2->commands[0];

    // Check the correct command name
    assert(strcmp(subcmd3->name, "cat") == 0);

    // Check the correct number of args of command
    assert(subcmd3->argc == 2);

    // Check if the arguments are correct
    assert(subcmd3->argv != NULL);
    
    assert(subcmd3->argv[0] != NULL);
    assert(subcmd3->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd3->argv[0]->value.simple, "cat") == 0);

    assert(subcmd3->argv[1] != NULL);
    assert(subcmd3->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd3->argv[1]->value.simple, "baz") == 0);

    assert(subcmd3->argv[2] == NULL);

    // Check the correct number of redirections
    assert(cmd->redirection_count == 1);

    // Check if the redirections are correct
    assert(cmd->redirections[0].type == REDIRECT_STDERR);
    assert(cmd->redirections[0].mode == REDIRECT_NO_OVERWRITE);
    assert(strcmp(cmd->redirections[0].filename, "bar") == 0);

    // Clean up
    free_pipeline(pip);
}

void test_parse_pipeline_with_multiple_pipe_substitutions() {
    
    // Set up
    char *input = "cat <(cat foo) <(cat baz)";
    pipeline *pip = parse_pipeline(input, false);

    // Check if the pipeline is NULL
    assert(pip != NULL);

    // Check the correct number of commands
    assert(pip->command_count == 1);

    // Call the command to test
    command *cmd = pip->commands[0];

    // Check the correct command name
    assert(strcmp(cmd->name, "cat") == 0);

    // Check the correct number of args of command
    assert(cmd->argc == 3);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);

    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "cat") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SUBSTITUTION);
    pipeline *subpip1 = cmd->argv[1]->value.substitution;

    // Check if the pipeline is NULL
    assert(subpip1 != NULL);

    // Check the correct number of commands
    assert(subpip1->command_count == 1);

    // Call the command to test
    command *subcmd1 = subpip1->commands[0];

    // Check the correct command name
    assert(strcmp(subcmd1->name, "cat") == 0);

    // Check the correct number of args of command
    assert(subcmd1->argc == 2);

    // Check if the arguments are correct
    assert(subcmd1->argv != NULL);

    assert(subcmd1->argv[0] != NULL);
    assert(subcmd1->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd1->argv[0]->value.simple, "cat") == 0);

    assert(subcmd1->argv[1] != NULL);
    assert(subcmd1->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd1->argv[1]->value.simple, "foo") == 0);

    assert(subcmd1->argv[2] == NULL);

    assert(cmd->argv[2] != NULL);
    assert(cmd->argv[2]->type == ARG_SUBSTITUTION);
    pipeline *subpip2 = cmd->argv[2]->value.substitution;

    // Check if the pipeline is NULL
    assert(subpip2 != NULL);

    // Check the correct number of commands
    assert(subpip2->command_count == 1);

    // Call the command to test
    command *subcmd2 = subpip2->commands[0];

    // Check the correct command name
    assert(strcmp(subcmd2->name, "cat") == 0);

    // Check the correct number of args of command
    assert(subcmd2->argc == 2);

    // Check if the arguments are correct
    assert(subcmd2->argv != NULL);

    assert(subcmd2->argv[0] != NULL);
    assert(subcmd2->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd2->argv[0]->value.simple, "cat") == 0);

    assert(subcmd2->argv[1] != NULL);
    assert(subcmd2->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd2->argv[1]->value.simple, "baz") == 0);

    assert(subcmd2->argv[2] == NULL);

    // Clean up
    free_pipeline(pip);
}

void test_parse_pipeline_list_with_pipes_substitutions() {
    
    // Set up
    char *input = "cat <(cat foo | grep bar <(cat baz)) 2> bar &";
    pipeline_list *pips = parse_pipeline_list(input);

    // Check if the pipelines of the list is not NULL
    assert(pips->pipelines != NULL);

    // Check the correct number of pipelines
    assert(pips->pipeline_count == 1);

    // Call the pipeline to test
    pipeline *pip = pips->pipelines[0];

    // Check if the pipeline has to_job
    assert(pip->to_job);

    // Check if the pipeline is NULL
    assert(pip != NULL);

    // Check the correct number of commands
    assert(pip->command_count == 1);

    // Call the command to test
    command *cmd = pip->commands[0];

    // Check the correct command name
    assert(strcmp(cmd->name, "cat") == 0);

    // Check the correct number of args of command
    assert(cmd->argc == 2);

    // Check if the arguments are correct
    assert(cmd->argv != NULL);
    
    assert(cmd->argv[0] != NULL);
    assert(cmd->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(cmd->argv[0]->value.simple, "cat") == 0);

    assert(cmd->argv[1] != NULL);
    assert(cmd->argv[1]->type == ARG_SUBSTITUTION);
    pipeline *subpip = cmd->argv[1]->value.substitution;

    // Check if the pipeline is NULL
    assert(subpip != NULL);

    // Check the correct number of commands
    assert(subpip->command_count == 2);

    // Call the command to test
    command *subcmd1 = subpip->commands[0];

    // Check the correct command name
    assert(strcmp(subcmd1->name, "cat") == 0);

    // Check the correct number of args of command
    assert(subcmd1->argc == 2);

    // Check if the arguments are correct
    assert(subcmd1->argv != NULL);

    assert(subcmd1->argv[0] != NULL);
    assert(subcmd1->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd1->argv[0]->value.simple, "cat") == 0);

    assert(subcmd1->argv[1] != NULL);
    assert(subcmd1->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd1->argv[1]->value.simple, "foo") == 0);

    assert(subcmd1->argv[2] == NULL);

    // Call the command to test
    command *subcmd2 = subpip->commands[1];

    // Check the correct command name
    assert(strcmp(subcmd2->name, "grep") == 0);

    // Check the correct number of args of command
    assert(subcmd2->argc == 3);

    // Check if the arguments are correct
    assert(subcmd2->argv != NULL);

    assert(subcmd2->argv[0] != NULL);
    assert(subcmd2->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd2->argv[0]->value.simple, "grep") == 0);

    assert(subcmd2->argv[1] != NULL);
    assert(subcmd2->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd2->argv[1]->value.simple, "bar") == 0);

    assert(subcmd2->argv[2] != NULL);
    assert(subcmd2->argv[2]->type == ARG_SUBSTITUTION);
    pipeline *subpip2 = subcmd2->argv[2]->value.substitution;

    // Check if the pipeline is NULL
    assert(subpip2 != NULL);

    // Check the correct number of commands
    assert(subpip2->command_count == 1);

    // Call the command to test
    command *subcmd3 = subpip2->commands[0];

    // Check the correct command name
    assert(strcmp(subcmd3->name, "cat") == 0);

    // Check the correct number of args of command
    assert(subcmd3->argc == 2);

    // Check if the arguments are correct
    assert(subcmd3->argv != NULL);
    
    assert(subcmd3->argv[0] != NULL);
    assert(subcmd3->argv[0]->type == ARG_SIMPLE);
    assert(strcmp(subcmd3->argv[0]->value.simple, "cat") == 0);

    assert(subcmd3->argv[1] != NULL);
    assert(subcmd3->argv[1]->type == ARG_SIMPLE);
    assert(strcmp(subcmd3->argv[1]->value.simple, "baz") == 0);

    assert(subcmd3->argv[2] == NULL);

    // Check the correct number of redirections
    assert(cmd->redirection_count == 1);

    // Check if the redirections are correct
    assert(cmd->redirections[0].type == REDIRECT_STDERR);
    assert(cmd->redirections[0].mode == REDIRECT_NO_OVERWRITE);
    assert(strcmp(cmd->redirections[0].filename, "bar") == 0);

    // Clean up
    free_pipeline_list(pips);
}

void test_invalid_pipe_substitution1() {
    
    // Set up
    char *input = "grep <( sort <( cat file1 | uniq";
    pipeline *pip = parse_pipeline(input, false);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}

void test_invalid_pipe_substitution2() {
    
    // Set up
    char *input = "wc -l <( | grep 'pattern')";
    pipeline *pip = parse_pipeline(input, false);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}

void test_invalid_pipe_substitution3() {
    
    // Set up
    char *input = "<( cat <( sort file1 ) )";
    pipeline *pip = parse_pipeline(input, false);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}

void test_invalid_pipe_substitution4() {

    // Set up
    char *input = "cat <( )";
    pipeline *pip = parse_pipeline(input, false);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}

void test_invalid_pipe_substitution5() {

    // Set up
    char *input = "cat <()";
    pipeline *pip = parse_pipeline(input, false);

    // Check if the pipeline is NULL
    assert(pip == NULL);
}
