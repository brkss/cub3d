



static int	ft_skip(const char **str)
{
	int	sign;

	sign = 1;
	while (*str && ((**str >= 9 && **str <= 13) || **str == 32))
		*str = *str + 1;
	if (**str == '-')
	{
		*str = *str + 1;
		sign *= -1;
	}
	else if (**str == '+')
		*str = *str + 1;
	return (sign);
}

int	ft_evil_atoi(const char *str)
{
	int					sign;
	unsigned long		result;

	result = 0;
	sign = ft_skip(&str);
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			result = result * 10 + (*str - '0');
		else
			return(-1);
		str++;
	}
	return (result * sign);
}
