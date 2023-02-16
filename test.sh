executables=("heaptest" "treetest" "huffman")
exampleDir="BIN/"
testFilesDir="TESTFILES/"
passed=0
testsNum=0

for executable in ${executables[@]}; do
    if [ "$executable" == "huffman" ]; then
        for testFile in "$testFilesDir"*; do
            exampleCommand=("./$exampleDir$executable $testFile")
            $exampleCommand > testExampleOutput
            projectCommand=("./$executable $testFile")
            $projectCommand > testProjectOutput

            testNum=$((testNum+1))

            if diff -q --text testExampleOutput testProjectOutput | grep "Files testExampleOutput and testProjectOutput differ" &> /dev/null; then
                printf "\n\n$projectCommand failed\n\n\n%-63s %s\n" "$exampleCommand Output" "$projectCommand Output"
                diff -y --text --color testExampleOutput testProjectOutput

            else
                echo "$projectCommand passed"
                passed=$((passed+1))
            fi
        done

    else
        exampleCommand=("./$exampleDir$executable")
        $exampleCommand > testExampleOutput
        projectCommand=(./$executable)
        $projectCommand > testProjectOutput

        testNum=$((testNum+1))

        if diff -q --text testExampleOutput testProjectOutput | grep "Files testExampleOutput and testProjectOutput differ" &> /dev/null; then
            printf "\n\n$projectCommand failed\n\n\n%-63s %s\n" "$exampleCommand Output" "$projectCommand Output"
            diff -y --text --color testExampleOutput testProjectOutput

        else
            echo "$projectCommand passed"
            passed=$((passed+1))
        fi
    fi
done

printf "\n %d/%d tests passed" $passed $testNum


rm testExampleOutput testProjectOutput
