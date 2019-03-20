package main

import "fmt"

func removeElement(nums []int,val int) int {
     i := 0
     for _,v := range nums {
        if v != val {
            nums[i] = v
            i++
        }
     }
     return i
}

func main() {
    // cretea a array
    b := []int{3,2,2,3}
    // call the function removeElement
    ret := removeElement(b,3)
    fmt.Println(b)
    fmt.Println(ret)
}
