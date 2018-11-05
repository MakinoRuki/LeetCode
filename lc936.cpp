target最终的形式必然是prefixprefix...|completestring|suffix..prefix..|completestring|suffix..prefix..|completestring|suffix..
因此可以先找出所有的completestring。
然后对于剩下的每一段，枚举suffix和prefix的分界点，再对于分出的前后两部分暴力匹配，是O(n)。因此总复杂度是n^2。

以上方法有漏洞：因为每一段可能有中缀。也就是可能形如后缀+中缀+前缀。

Another Solution：
每次选一段完整的全部标成???。然后对于已经带有？？？的则match形如prefix+???或者???+suffix的串。
由于每次会跳过检查已经全部为？？？的串，因此均摊为n^2。
