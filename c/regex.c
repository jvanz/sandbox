
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

/**
 * Function to print an regex error
 */
void print_regerror(int errcode, const regex_t *preg)
{
	printf("print_regerror(%d)\n", errcode);
	size_t buffer_size = 256;
	char buffer[buffer_size];
	regerror(errcode, preg, buffer, buffer_size);
	printf("error: %s\n", buffer);

}

int main(int argc, char** argv)
{
	regex_t preg;
	const char *regex = "^[A-Za-z_][.A-Za-z0-9_-]*$";
	const char *test_string = "dummy_dev-ice.console";

	// compile regex
	int ret = regcomp(&preg, regex, REG_EXTENDED);
	if (ret != 0)  {
		print_regerror(ret, &preg);
		regfree(&preg);
		return -1;
	}

	// try to match something
	size_t nmatch = 1;
	regmatch_t matches[nmatch];
	ret = regexec(&preg, test_string, nmatch, matches, 0);
	if (ret != 0)  {
		print_regerror(ret, &preg);
		regfree(&preg);
		return -1;
	}

	// get the matched text
	int match_size = matches[0].rm_eo - matches[0].rm_so;
	char matchstr[match_size+1];
	matchstr[match_size+1] = '\0';
	strncpy(matchstr, test_string + matches[0].rm_so, match_size);
	printf("match: %s\n", matchstr);
}
