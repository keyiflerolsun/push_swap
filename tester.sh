#!/bin/bash

# Renk Tanımları
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
MAGENTA="\033[1;35m"
CYAN="\033[1;36m"
RESET="\033[0m"
BOLD="\033[1m"

# Test sayısını argümandan al, yoksa 3 yap
TEST_COUNT=${1:-3}

# Puanlama Fonksiyonu
function calculate_score {
  local SIZE=$1
  local STEPS=$2

  if [ "$SIZE" -eq 100 ]; then
    if [ "$STEPS" -lt 700 ]; then echo 5
    elif [ "$STEPS" -lt 900 ]; then echo 4
    elif [ "$STEPS" -lt 1100 ]; then echo 3
    elif [ "$STEPS" -lt 1300 ]; then echo 2
    elif [ "$STEPS" -lt 1500 ]; then echo 1
    else echo 0; fi

  elif [ "$SIZE" -eq 500 ]; then
    if [ "$STEPS" -lt 5500 ]; then echo 5
    elif [ "$STEPS" -lt 7000 ]; then echo 4
    elif [ "$STEPS" -lt 8500 ]; then echo 3
    elif [ "$STEPS" -lt 10000 ]; then echo 2
    elif [ "$STEPS" -lt 11500 ]; then echo 1
    else echo 0; fi
  else
    echo "-"
  fi
}

function run_test {
  local SIZE=$1
  printf "\n${BOLD}${MAGENTA}===== %d TESTS FOR SIZE %d =====${RESET}\n" "$TEST_COUNT" "$SIZE"

  # Başlık
  printf "${CYAN}${BOLD}%6s %7s %7s %8s${RESET}\n" "SIZE" "STEPS" "GRADE" "SCORE"
  printf "${MAGENTA}---------------------------------${RESET}\n"

  for i in $(seq 1 $TEST_COUNT); do
    ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-10000, 10000), $SIZE))))")
    OUT=$(./push_swap $ARG)
    STEP_COUNT=$(echo "$OUT" | wc -l)
    RESULT=$(echo "$OUT" | ./checker_linux $ARG)
    SCORE=$(calculate_score $SIZE $STEP_COUNT)

    # SCORE rengini seç
    if [ "$SCORE" -eq 4 ]; then
      SCORE_COLOR=$YELLOW
    elif [ "$SCORE" -eq 5 ]; then
      SCORE_COLOR=$GREEN
    else
      SCORE_COLOR=$RED
    fi

    # GRADE metnini hizala ve renklendir
    GRADE_TEXT=$(printf "%7s" "$RESULT")
    GRADE=$(printf "%b%b%b%b" "$GREEN" "$BOLD" "$GRADE_TEXT" "$RESET")
    if [ "$RESULT" != "OK" ]; then
      GRADE=$(printf "%b%b%b%b" "$RED" "$BOLD" "$GRADE_TEXT" "$RESET")
    fi

    # SCORE metnini hizala ve renklendir
    SCORE_TEXT=$(printf "%8s" "[$SCORE/5]")
    SCORE_COLORED=$(printf "%b%b%b%b" "$SCORE_COLOR" "$SCORE_TEXT" "$RESET" "")

    # Sonuçları yazdır
    printf "${BLUE}%6d ${YELLOW}%7d${RESET} %s %s\n" "$SIZE" "$STEP_COUNT" "$GRADE" "$SCORE_COLORED"
  done
  printf "\n"
}

# Testleri çalıştır
run_test 100
run_test 500
