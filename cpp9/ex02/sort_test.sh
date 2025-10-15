#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "================================"
echo "PmergeMe Sort Verification Test"
echo "================================"
echo

test_case() {
    local size=$1
    local range=$2

    echo "Testing with $size elements (range: 1-$range)..."

    NUMBERS=$(shuf -i 1-$range -n $size | tr "\n" " ")

    OUTPUT=$(./PmergeMe $NUMBERS 2>&1)

    BEFORE=$(echo "$OUTPUT" | grep "^Before:" | sed 's/Before: //')
    AFTER=$(echo "$OUTPUT" | grep "^After:" | sed 's/After: //')

    SORTED=$(echo $BEFORE | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
    RESULT=$(echo $AFTER | sed 's/ $//')

    if [ "$SORTED" = "$RESULT" ]; then
        echo -e "${GREEN}✓ PASS${NC}: Sort is correct"
    else
        echo -e "${RED}✗ FAIL${NC}: Sort is incorrect"
        echo "Expected first 10: $(echo $SORTED | cut -d' ' -f1-10)"
        echo "Got first 10:      $(echo $RESULT | cut -d' ' -f1-10)"

        BEFORE_COUNT=$(echo $BEFORE | wc -w)
        AFTER_COUNT=$(echo $RESULT | wc -w)
        echo "Before count: $BEFORE_COUNT, After count: $AFTER_COUNT"

        if [ "$BEFORE_COUNT" != "$AFTER_COUNT" ]; then
            echo -e "${RED}Element count mismatch!${NC}"
        fi

        DIFF_OUTPUT=$(diff <(echo $SORTED | tr ' ' '\n') <(echo $RESULT | tr ' ' '\n') | head -20)
        if [ ! -z "$DIFF_OUTPUT" ]; then
            echo -e "${YELLOW}First differences:${NC}"
            echo "$DIFF_OUTPUT"
        fi

        return 1
    fi

    echo
    return 0
}

if [ ! -f "./PmergeMe" ]; then
    echo -e "${RED}Error: PmergeMe executable not found${NC}"
    echo "Please compile first: make"
    exit 1
fi

FAILED=0

test_case 10 100 || FAILED=$((FAILED + 1))
test_case 50 1000 || FAILED=$((FAILED + 1))
test_case 100 10000 || FAILED=$((FAILED + 1))
test_case 500 50000 || FAILED=$((FAILED + 1))
test_case 1000 100000 || FAILED=$((FAILED + 1))
test_case 3000 100000 || FAILED=$((FAILED + 1))

echo "================================"
if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
else
    echo -e "${RED}$FAILED test(s) failed${NC}"
fi
echo "================================"

exit $FAILED