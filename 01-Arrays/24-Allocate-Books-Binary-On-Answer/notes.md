# Allocate Books

## Pattern

Binary Search on Answer
+
Greedy Allocation

## Goal

Minimize the maximum number of pages assigned
to any student.

Books must be allocated in order.

Each student must receive at least one book.

---

## Search Space

Minimum:

max(pages)

Because the largest book must be assigned to
some student.

Maximum:

sum(pages)

Because one student could receive all books.

---

## Feasibility Check

Given maxPages:

Start with:

studentsUsed = 1
current = pages[0]

Traverse the books.

If:

current + pages[i] <= maxPages

assign the book to the current student.

Otherwise:

studentsUsed++
current = pages[i]

At the end:

studentsUsed <= students

means the candidate works.

IMPORTANT:

Use <=, NOT ==.

We need AT MOST the allowed number of students.

---

## Why <=?

If we have 3 students available but only need
2 students, the allocation is still possible.

Therefore:

studentsUsed <= students

---

## Binary Search

We want the MINIMUM valid maximum page limit.

If candidate works:

right = mid - 1

Try a smaller maximum.

If candidate doesn't work:

left = mid + 1

Need to allow more pages per student.

Final answer:

left

---

## Pattern

❌ ❌ ❌ ❌ ✅ ✅ ✅
            ↑
      minimum valid

---

## Edge Case

If:

students > number of books

return -1

because every student must receive at least
one book.

---

## Complexity

Let:

n = number of books
S = sum of pages

Feasibility check:

O(n)

Binary Search:

O(log S)

Total:

O(n log S)

Space:

O(1)