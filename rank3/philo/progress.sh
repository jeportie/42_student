# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    progress.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 15:01:42 by jeportie          #+#    #+#              #
#    Updated: 2024/09/12 15:33:45 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/zsh

# Usage: ./progress.sh TOTAL LOG_FILE

TOTAL=$1
LOG_FILE=$2

# Count the total lines in the log file
STEP=0

# Read the log file and update progress based on the steps processed
while read -r line; do
    STEP=$((STEP + 1))

    # Calculate percentage based on the number of steps
    PERCENT=$(( STEP * 100 / TOTAL ))

    # Calculate the length of the progress bar (out of 20)
    BAR_LENGTH=$(( STEP * 20 / TOTAL ))

    # Clear the line and print progress bar with green color and fill with `#`
    printf "\r\033[32m[%-20s] %d%%\033[0m" $(printf '#%.0s' {1..$BAR_LENGTH}) $PERCENT
done < "$LOG_FILE"

# Move to a new line when progress reaches 100%
echo "\nCompilation complete."

