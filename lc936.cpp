target最终的形式必然是prefixprefix...|completestring|suffix..prefix..|completestring|suffix..prefix..|completestring|suffix..
因此可以先找出所有的completestring。
然后对于剩下的每一段，枚举suffix和prefix的分界点，再对于分出的前后两部分暴力匹配，是O(n)。因此总复杂度是n^2。
