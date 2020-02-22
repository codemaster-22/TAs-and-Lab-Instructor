# TAs-and-Lab-Instructor
Finding the Minimal Spanning Tree

Problem Statement
- N students in IIT Madras want to be Teaching Assistants(TA) for the OOAIA lab. However, TAs need to
set the problems and create test cases for each lab. But you might have heard the famous Joker’s saying, “if you
are good at something, never do that for free”. Taking inspiration from Joker, students demand money to work
as a TA. All the TAs work in pairs(teams of 2) and each pair demands x(It is guaranteed that x can only
take up to two distinct values) rupees for working in the lab. Two students who can work(if they become
TAs) together are called partners. However, some of the students dislike each other and refuse to work(if they
become TAs) together, which might be problematic to the lab instructor. So for the lab to run smoothly, the
instructor has set his/her own criteria to select a few students to be the TAs out of N students.
- Conditions to be fulfilled by each student if he/she is to be selected as a TA:
1. All his/her partners should also be selected
2. No student whom he/she dislikes should be selected
3. All the students who have been selected should be connected with him/her either directly(partners) or
through a chain of partner relations. Students s1 and sk are said to be connected through a chain of
partner relations if there is a sequence of students s1, s2, s3, . . . , sk - 1, sk such that si and si+1(1 ≤ i < k)
are partners.
- See the example below for clarity on Conditions
- However, the Instructor has to pay money for all the partner pairs separately if he/she wants that set of partners
to work together in the lab. So, in order to keep the money expenditure minimum while having the maximum
number of TAs(Greedy Instructor), the instructor proposes a relaxation condition that can be applied to the
already selected group of students who satisfied the above 3 conditions.
Relaxation Condition: The instructor can delete a partner relation(si
, sj who are initially partners are no
longer partners after applying this condition on partner relation(si
,sj)) to avoid paying them. Note: All the
above 3 conditions should still hold after applying this relaxation condition on the group.
- Find the maximum number of students who can be selected as TAs. Then find the minimum amount of
money needed to be spent on selecting such a group(Group containing the maximum number of students) after
applying relaxation condition on this group any number of times - possibly zero.
- Input Format
- The first line of input contains an integer N(1 ≤ N ≤ 10^5
), the number of students who want to work as TAs.
- The second line contains an integer m(0 ≤ m ≤ min(10^6
,
(N∗(N−1))
2
)) — the number of pairs of partners.
- Each of the next m lines contains three space separated integers ui
, vi
, xi (1 ≤ ui
, vi ≤ N, ui != vi and 1 ≤ xi ≤ 10^5
)
– indices of the students who form i-th pair of partners and money demanded by this pair to work in the lab(if
selected as TAs) respectively.
- The next line contains an integer p(0 ≤ p ≤ min(10^6
,
(N∗(N−1))
2
)) — the number of pairs of students who dislike
each other. Each of the next p lines contains two space separated integers ui
, vi(1 ≤ ui
, vi ≤ N, ui != vi) — i-th
1
- pair of students who dislike each other.
- Each pair of people is mentioned in the input atmost once(m + p ≤
(N∗(N−1))/
2
).
- Output Format
- Output two space-separated integers — the maximum number of students that can be selected as TAs and the
minimum amount of money needed to be spent on selecting such a group respectively.
- If it is not possible to select atleast two students, then print -1.
